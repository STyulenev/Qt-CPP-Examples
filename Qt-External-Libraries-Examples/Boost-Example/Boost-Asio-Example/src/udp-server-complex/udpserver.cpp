#include "udpserver.h"

#include <iostream>

UdpServer::UdpServer(unsigned short port) :
    _io_context(),
    _socket(_io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
    _running(false)
{
    std::cout << "UDP server configured on port: " << port << std::endl;
}

UdpServer::~UdpServer()
{
    stop();
}

void UdpServer::start()
{
    if (_running)
    {
        return;
    }

    _running = true;

    _io_thread = std::thread([this]() {
        auto work_guard = boost::asio::make_work_guard(_io_context);
        start_receive();
        _io_context.run();
    });
}

void UdpServer::stop()
{
    if (!_running)
    {
        return;
    }

    _running = false;

    // Закрываем сокет, чтобы прервать ожидающие операции
    boost::system::error_code ec;
    _socket.close(ec);

    _io_context.stop();

    if (_io_thread.joinable())
    {
        _io_thread.join();
    }

    std::cout << "UDP server stopped." << std::endl;
}

void UdpServer::start_receive()
{
    auto buffer = std::make_shared<std::array<char, 1024>>();
    auto sender = std::make_shared<boost::asio::ip::udp::endpoint>();

    _socket.async_receive_from(boost::asio::buffer(*buffer), *sender,
        [this, buffer, sender](const boost::system::error_code& ec, std::size_t length) {
            if (!ec)
            {
                // Отправляем те же данные обратно
                std::cout << "Obtained data: " << buffer->data() << "\n";

                auto reply = std::make_shared<std::string>(buffer->data(), length);

                _socket.async_send_to(boost::asio::buffer(*reply), *sender,
                    [this, reply]([[maybe_unused]] const boost::system::error_code& ec, [[maybe_unused]] std::size_t sent) {
                        // После отправки снова начинаем приём
                        if (_running)
                        {
                            start_receive();
                        }
                    });
            }
            else if (ec == boost::asio::error::operation_aborted)
            {
                // ...
            }
            else
            {
                std::cerr << "Receive error: " << ec.message() << std::endl;

                if (_running)
                {
                    start_receive();
                }
            }
        });
}
