#include "listener.h"

#include <iostream>

int main(int argc, char* argv[])
{
    const auto address = boost::asio::ip::make_address("0.0.0.0");
    const unsigned short port = 8080;

    boost::asio::io_context ioc{1};

    std::make_shared<Listener>(ioc, boost::asio::ip::tcp::endpoint{address, port})->run();

    std::cout << "WebSocket server listening on port " << port << '\n';

    ioc.run();

    return 0;
}
