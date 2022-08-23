/**
 * @file socket.h
 * @author Roman Permyakov (RA.Permyakov@npo-nauka.ru)
 * @brief Custom asio socket for CAN-bus
 * @version 0.1
 * @date 2022-08-23
 *
 * @copyright Copyright (c) 2022
 */

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
     * @brief Main class. Wrapper of native linux can socket
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
        /**
         * @brief Construct a new socket object
         *
         * @param ifn interface name
         * @param io_context boost::asio::io_context&
         */
        socket(const std::string &ifn, boost::asio::io_context &io_context);

        /**
         * @brief Get the Native Socket object
         *
         * @return raw_protocol_t::socket&
         */
        raw_protocol_t::socket &getNativeSocket();

        /**
         * @brief Get the Endpoint object
         *
         * @return raw_endpoint_t&
         */
        raw_endpoint_t &getEndpoint();

        /**
         * @brief Get the frame buffer
         *
         * @return can_frame&
         */
        can_frame &getRecFrame();

        /**
         * @brief Get the Interface Name
         *
         * @return const std::string&
         */
        const std::string &getInterfaceName();
        virtual ~socket();
    };
}
#endif // PICAN_SOCKET_H