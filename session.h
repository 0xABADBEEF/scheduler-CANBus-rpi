/**
 * @file session.h
 * @author Roman Permyakov (RA.Permyakov@npo-nauka.ru)
 * @brief Class session is used to group can-bus sockets and dds-layer into a single working unit.
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef PICAN_SESSION_H
#define PICAN_SESSION_H

#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/subscriber/SubscriberListener.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastrtps/rtps/common/Types.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastdds/dds/subscriber/DataReader.hpp>

#include <boost/noncopyable.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <linux/can.h>

#include "dataPubSubTypes.h"
#include <boost/asio.hpp>

#include "socket.h"

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastrtps::types;

using error_code = boost::system::error_code;

class session : public boost::noncopyable, DataReaderListener
{
private:
    /**
     * Callback from DataReaderListener (dds-layer).
     *
     * @brief Method is called when a new Data Message (can_frame_from_dds or modification or config) was received.
     * @param reader DataReader pointer which is saved in session.readers;
     */
    void on_data_available(DataReader *reader) override;

    /**
     * Callback from DataReaderListener (dds-layer).
     *
     * @brief Method called when the subscriber is matched with a new Writer (or unmatched).
     * @param reader DataReader pointer which is saved in session.readers;
     * @param info The subscription matched status
     */
    void on_subscription_matched(DataReader *reader, const SubscriptionMatchedStatus &info) override;

    /**
     * @brief Method starts transferring data between can-bus sockets, providing configuration and validation checks.
     *
     * @param l_socket0 sender socket
     * @param l_socket1 receiver socket
     */
    void start_linked_sockets_loop(can::socket &l_socket0, can::socket &l_socket1);

    /**
     * Deprecated.
     *
     * @brief Prints can_frame. It's Thread-safe, but very slow.
     * @param ifn name of interface (can0, vcan4 etc.)
     * @param rec_frame can_frame with received data
     */
    [[maybe_unused]] static void print_msg(const std::string &ifn, can_frame &rec_frame);

    /**
    * @brief
    * @tparam T
    * @param reader
    * @param info
    * @param data
    * @param handler
    */
    template<class T>
    void take_new_sample(DataReader *reader, SampleInfo &info, T &data, const std::function<void()> &handler) const;

    /**
     * @brief
     * @return
     */
    void check_modification_buffer(can_frame& frame);

    /**
     * @brief
     * @param socket
     * @param frame
     */
    void send_to_socket(can::socket &socket, can_frame &frame);

    /**
     * @brief
     * @param dds
     * @return
     */
    can::socket &get_sock_by_ifn(can_frame_from_dds &dds);

    /**
     *
     * @param ifn
     * @param frame
     */
    void publish_data(std::string ifn, can_frame &frame);
public:
    /**
     * @brief Constructor
     * @param ifn0 name of interface for the first socket
     * @param ifn1 name of interface for the second socket
     * @param io_context boost::asio::io_context
     */
    session(const std::string &ifn0, const std::string &ifn1, boost::asio::io_context &io_context);

    /**
     * @brief Destructor.
     */
    virtual ~session();

    /**
     * DDS-layer Initialization.
     *
     * @brief Creates participant, publisher, subscriber, writers/readers and topics.
     * @return true if everything was created successfully
     */
    bool init();

    /**
    * @brief
    */
    void start_linked_sockets_loop();

    /**
     * @brief Session's main loop.
     */
    [[noreturn]] inline void run()
    {
        while (true)
        {}
    }
private:
    boost::asio::io_context &io_context;
    DomainParticipant *participant;
    Publisher *publisher;
    Subscriber *subscriber;
    std::map<DataReader *, Topic *> readers;
    std::map<Topic *, DataWriter *> writers;
    boost::asio::io_context::strand read_worker;
    boost::asio::io_context::strand write_worker;
    can::socket socket0;
    can::socket socket1;
    std::map<uint32_t, can_frame> mod_list;
};

#endif //PICAN_SESSION_H