#pragma once

#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>

// Слушатель: принимает входящие TCP-соединения
class Listener : public std::enable_shared_from_this<Listener>
{
public:
    Listener() = delete;
    Listener(boost::asio::io_context& ioc, boost::asio::ip::tcp::endpoint endpoint);

    void run();

private:
    void do_accept();
    void on_accept(boost::beast::error_code ec, boost::asio::ip::tcp::socket socket);

private:
    boost::asio::io_context&       _io_context;
    boost::asio::ip::tcp::acceptor _acceptor;

};
