#include "socket.h"

can::socket::socket(const std::string &ifn, boost::asio::io_context &io_context)
    : native_socket(io_context, raw_protocol_t(PF_CAN, CAN_RAW)), interface_name(ifn), read(io_context), write(io_context)
{
    addr.can_family = AF_CAN;
    addr.can_ifindex = if_nametoindex(ifn.c_str());
    endpoint = raw_endpoint_t(&addr, sizeof(sockaddr_can));
    native_socket.bind(endpoint);
}

can::socket::~socket()
{
    native_socket.close();
}

can::raw_protocol_t::socket &can::socket::getNativeSocket()
{
    return native_socket;
}

const std::string &can::socket::getInterfaceName()
{
    return interface_name;
}

can::raw_endpoint_t &can::socket::getEndpoint()
{
    return endpoint;
}

can_frame &can::socket::getRecFrame()
{
    return rec_frame;
}
