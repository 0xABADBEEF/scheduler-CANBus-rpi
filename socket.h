#ifndef PICAN_SOCKET_H
#define PICAN_SOCKET_H

#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>

#include <linux/can.h>

namespace can
{
    typedef boost::asio::generic::raw_protocol raw_protocol_t;
    typedef boost::asio::generic::basic_endpoint<raw_protocol_t> raw_endpoint_t;

    /**
     * @brief
     *
     */
    class socket : public boost::noncopyable
    {
    private:
        std::string interface_name;
        struct sockaddr_can addr;
        raw_protocol_t::socket native_socket;
        struct can_frame rec_frame;
        raw_endpoint_t endpoint;

    public:
        boost::asio::io_context::strand read;
        boost::asio::io_context::strand write;

    public:
        socket(const std::string &ifn, boost::asio::io_context &io_context);
        raw_protocol_t::socket &getNativeSocket();
        raw_endpoint_t &getEndpoint();
        can_frame &getRecFrame();
        const std::string &getInterfaceName();
        virtual ~socket();
    };
}
#endif // PICAN_SOCKET_H