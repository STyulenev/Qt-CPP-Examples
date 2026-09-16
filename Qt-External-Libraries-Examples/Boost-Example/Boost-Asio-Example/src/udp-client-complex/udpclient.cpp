#include "udpclient.h"

#include <iostream>

UdpClient::UdpClient(const std::string& host, const std::string& port) :
    _io_context(),
    _socket(_io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8081)),
    _resolver(_io_context),
    _is_running(false)
{
    _server_endpoint = *_resolver.resolve(boost::asio::ip::udp::v4(), host, port).begin();
}

UdpClient::~UdpClient()
{
    stop();
}

void UdpClient::send(const std::string& message)
{
    if (_is_running)
    {
        return;
    }

    _is_running = true;

    _io_thread = std::thread([this, message]() {
        auto work_guard = boost::asio::make_work_guard(_io_context);

        auto msg = std::make_shared<std::string>(message);
        _socket.async_send_to(
            boost::asio::buffer(*msg), _server_endpoint,
            [this, msg](const boost::system::error_code& ec, [[maybe_unused]] std::size_t sent) {
                if (!ec)
                {
                    start_receive();
                }
                else
                {
                    std::cerr << "Send error: " << ec.message() << "\n";
                    _io_context.stop();
                }
            });

        _io_context.run();
    });
}

void UdpClient::wait()
{
    if (_io_thread.joinable())
    {
        _io_thread.join();
    }
}

void UdpClient::stop()
{
    if (!_is_running)
    {
        return;
    }

    _is_running = false;

    boost::system::error_code ec;
    _socket.close(ec);
    _io_context.stop();

    if (_io_thread.joinable())
    {
        _io_thread.join();
    }
}

void UdpClient::set_on_reply(std::function<void (const std::string&)> cb)
{
    _on_reply = std::move(cb);
}

void UdpClient::start_receive()
{
    auto buffer = std::make_shared<std::array<char, 1024>>();

    _socket.async_receive_from(
        boost::asio::buffer(*buffer), _sender_endpoint,
        [this, buffer](const boost::system::error_code& ec, std::size_t length) {
            if (!ec)
            {
                std::string reply(buffer->data(), length);

                if (_on_reply)
                {
                    _on_reply(reply);
                }
                // Для одного запроса-ответа завершаем работу
                _is_running = false;
                _io_context.stop();
            }
            else
            {
                std::cerr << "Receive error: " << ec.message() << "\n";
                _is_running = false;
                _io_context.stop();
            }
        });
}
