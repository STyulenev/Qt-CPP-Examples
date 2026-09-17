#pragma once

#include <boost/asio.hpp>
#include <memory>

// Сессия: обработка одного подключения
class Session : public std::enable_shared_from_this<Session>
{
public:
    Session() = delete;
    explicit Session(boost::asio::ip::tcp::socket socket);

    void start();

private:
    void do_read();
    void do_write(std::size_t length);

private:
    boost::asio::ip::tcp::socket _socket;
    boost::asio::strand<boost::asio::ip::tcp::socket::executor_type> _strand;
    char _data[1024];

};
