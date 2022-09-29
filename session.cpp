#include "session.h"

boost::mutex print_mutex;
boost::mutex mod_lock;

session::session(const std::string &ifn0, const std::string &ifn1, boost::asio::io_context &_io_context)
    : participant{nullptr}, publisher{nullptr}, subscriber{nullptr}, read_worker{io_context},
      write_worker{io_context}, socket0{ifn0, io_context}, socket1{ifn1, io_context}, io_context{_io_context}
{
}

bool session::init()
{
    participant = DomainParticipantFactory::get_instance()->create_participant(0 /*DomainID*/,
                                                                               PARTICIPANT_QOS_DEFAULT);

    if (participant == nullptr)
        throw std::runtime_error("Cannot create domain participant.");

    TypeSupport can_frame_from_dds_type(new can_frame_from_ddsPubSubType());
    can_frame_from_dds_type.register_type(participant);
    TypeSupport can_frame_from_bus_type(new can_frame_from_busPubSubType());
    can_frame_from_bus_type.register_type(participant);
    TypeSupport modification_type(new modificationPubSubType());
    modification_type.register_type(participant);
    // cfg mod

    publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT);
    Topic *topic = participant->create_topic("can_frame_from_bus" /*ID_RPI_data*/,
                                             can_frame_from_bus_type.get_type_name(),
                                             TOPIC_QOS_DEFAULT);

    if (topic == nullptr)
        throw std::runtime_error("Cannot create topic entity.");

    DataWriter *writer = publisher->create_datawriter(topic, DATAWRITER_QOS_DEFAULT);

    if (publisher == nullptr || writer == nullptr)
    {
        throw std::runtime_error("Cannot create publisher.");
    }

    writers[topic] = writer;

    topic = participant->create_topic("can_frame_from_dds",
                                      can_frame_from_dds_type.get_type_name(),
                                      TOPIC_QOS_DEFAULT);

    if (nullptr == topic)
        throw std::runtime_error("Cannot create topic entity.");

    subscriber = participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT);
    DataReader *reader = subscriber->create_datareader(topic, DATAREADER_QOS_DEFAULT, this);

    if (subscriber == nullptr || reader == nullptr)
    {
        throw std::runtime_error("Cannot create subscriber.");
    }

    readers[reader] = topic;

    topic = participant->create_topic("modification_type",
                                      modification_type.get_type_name(),
                                      TOPIC_QOS_DEFAULT);

    reader = subscriber->create_datareader(topic, DATAREADER_QOS_DEFAULT, this);
    readers[reader] = topic;

    if (topic == nullptr || reader == nullptr)
    {
        throw std::runtime_error("Cannot create subscriber.");
    }

    return true;
}

void session::on_data_available(DataReader *reader)
{
    boost::asio::post(read_worker, [this, reader]()
                      {
        SampleInfo info;
        auto type = readers[reader]->get_type_name();

        if (boost::equals(type, "can_frame_from_dds"))
        {
            can_frame_from_dds data;
            take_new_sample(reader, info, data, [this, &data]()
            {
                can_frame frame{};
                frame.can_id = 0x12;
                frame.can_dlc = 8;

                for (int i = 0; i < frame.can_dlc; i++)
                    frame.data[i] = /*data.data()[i]*/ 0xFF;
                //TODO:
                send_to_socket(/*get_sock_by_ifn(data)*/ socket1, frame);
            });
            return;
        }
        else if (boost::equals(type, "config_from_dds"))
        {
            //TODO:
            return;
        }
        else if (boost::equals(type, "modification_type"))
        {
            modification mod;
            take_new_sample(reader, info, mod, [this, &mod]()
            {
                can_frame frame;
                frame.can_id = mod.id();
                frame.data[0] = 0xAF;
                {
                    boost::lock_guard<boost::mutex> lock(mod_lock);
                    mod_list[frame.can_id] = frame;
                }
            });
            return;
        }
        else
        {
//                throw std::runtime_error("Unknown topic received.");
        } });
}

template <class T>
void session::take_new_sample(DataReader *reader, SampleInfo &info, T &data, const std::function<void()> &handler) const
{
    if (reader->take_next_sample(&data, &info) == ReturnCode_t::RETCODE_OK &&
        info.instance_state == ALIVE_INSTANCE_STATE)
    {
        handler();
    }
}

void session::on_subscription_matched(DataReader *reader, const SubscriptionMatchedStatus &info)
{
}

void session::start_linked_sockets_loop(can::socket &l_socket0, can::socket &l_socket1)
{
    l_socket0.getNativeSocket().async_receive(
        boost::asio::buffer(&l_socket0.getRecFrame(), sizeof(l_socket0.getRecFrame())),
        boost::asio::bind_executor(l_socket0.read,
                                   [this, &l_socket0, &l_socket1](error_code error, std::size_t bytes_transferred)
                                   {
                                       //                       if (cfg.is_transmitting_on)
                                       {
                                           if (!error)
                                           {
                                               can_frame received_frame = l_socket0.getRecFrame();

                                               check_modification_buffer(received_frame);
                                               publish_data(std::string(), received_frame);
                                               send_to_socket(l_socket1, received_frame);
                                               start_linked_sockets_loop(l_socket0, l_socket1);
                                           }
                                       }
                                   }));
}

void session::send_to_socket(can::socket &socket, can_frame &frame)
{
    socket.getNativeSocket().send(
        boost::asio::buffer(&frame, sizeof(frame)));
    //            boost::asio::bind_executor(socket.write, [](error_code error, std::size_t bytes_transferred)
    //            {
    //                if (!error)
    //                {
    //
    //                }
    //            }));
}

void session::start_linked_sockets_loop()
{
    // FIXME:
    start_linked_sockets_loop(socket0, socket1);
    start_linked_sockets_loop(socket1, socket0);
}

void session::print_msg(const std::string &ifn, can_frame &rec_frame)
{
    {
        boost::lock_guard<boost::mutex> lock(print_mutex);

        std::cout << std::setw(4) << ifn << " " << std::setw(5)
                  << std::hex << std::uppercase << rec_frame.can_id
                  << std::setw(4) << "[" << int(rec_frame.can_dlc) << "]  ";

        for (int i = 0; i < rec_frame.can_dlc; i++)
        {
            std::cout << std::hex << std::uppercase << int(rec_frame.data[i]) << " ";
        }
        std::cout << std::endl;
    }
}

void session::check_modification_buffer(can_frame &frame)
{
    if (mod_list.contains(frame.can_id))
    {
        boost::lock_guard<boost::mutex> lock(mod_lock);
        frame = mod_list[frame.can_id];
    }
}

[[maybe_unused]] can::socket &session::get_sock_by_ifn(can_frame_from_dds &dds)
{
    //        return <#initializer#>;
}

session::~session()
{
    socket0.~socket();
    socket1.~socket();

    for (const auto &kv : readers)
    {
        subscriber->delete_datareader(kv.first);
        participant->delete_topic(kv.second);
    }

    for (const auto &kv : writers)
    {
        publisher->delete_datawriter(kv.second);
        participant->delete_topic(kv.first);
    }

    if (publisher != nullptr)
    {
        participant->delete_publisher(publisher);
    }
    if (subscriber != nullptr)
    {
        participant->delete_subscriber(subscriber);
    }

    DomainParticipantFactory::get_instance()->delete_participant(participant);
}

void session::publish_data(std::string ifn, can_frame &frame)
{
    for (const auto &kv : writers)
    {
        if (boost::equals(kv.first->get_type_name(), "can_frame_from_bus"))
        {
            can_frame_from_bus data;

            data.ifn() = 0;
            data.id() = frame.can_id;
            data.dataSize() = frame.can_dlc;

            for (int i = 0; i < frame.can_dlc; i++)
                data.data()[i] = frame.data[i];

            kv.second->write(&data);
        }
    }
}