#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>

// Обработчик одного WebSocket-соединения
class Session : public std::enable_shared_from_this<Session>
{
public:
    Session() = delete;
    explicit Session(boost::asio::ip::tcp::socket&& socket);

    void run();

private:
    void on_accept(boost::beast::error_code ec);

    void do_read();

    void on_read(boost::beast::error_code ec, std::size_t bytes_transferred);
    void on_write(boost::beast::error_code ec, std::size_t bytes_transferred);

private:
    boost::beast::websocket::stream<boost::beast::tcp_stream> _ws; // WebSocket, через который идёт вся работа с соединением
    boost::beast::flat_buffer _buffer; // Буфер для чтения

};
