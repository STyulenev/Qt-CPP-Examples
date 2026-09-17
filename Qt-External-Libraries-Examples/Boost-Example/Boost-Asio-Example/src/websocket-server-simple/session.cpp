#include "session.h"

#include <iostream>

Session::Session(boost::asio::ip::tcp::socket&& socket) :
    _ws(std::move(socket))
{

}

void Session::run()
{
    // Устанавливаем таймауты для сервера
    _ws.set_option(boost::beast::websocket::stream_base::timeout::suggested(boost::beast::role_type::server));

    // Устанавливаем заголовок Server в ответе на handshake
    _ws.set_option(boost::beast::websocket::stream_base::decorator(
        [](boost::beast::websocket::response_type& res) {
            res.set(boost::beast::http::field::server, "Boost.Beast WebSocket Server");
        }));

    // Принимаем handshake и начинаем чтение
    _ws.async_accept(boost::beast::bind_front_handler(&Session::on_accept, shared_from_this()));
}

void Session::on_accept(boost::beast::error_code ec)
{
    if (ec)
    {
        std::cerr << "Accept: " << ec.message() << std::endl;
        return;
    }

    do_read();
}

void Session::do_read()
{
    _ws.async_read(_buffer, boost::beast::bind_front_handler(&Session::on_read, shared_from_this()));
}

void Session::on_read(boost::beast::error_code ec, [[maybe_unused]] std::size_t bytes_transferred)
{
    if (ec == boost::beast::websocket::error::closed)
    {
        // Клиент закрыл соединение нормально
        return;
    }

    if (ec)
    {
        std::cerr << "Read: " << ec.message() << std::endl;
        return;
    }

    std::string message = boost::beast::buffers_to_string(_buffer.data());
    std::cout << "Received: " << message << std::endl;

    // Эхо: отправляем полученное сообщение обратно
    _ws.text(_ws.got_text());
    _ws.async_write(_buffer.data(), boost::beast::bind_front_handler(&Session::on_write, shared_from_this()));
}

void Session::on_write(boost::beast::error_code ec, [[maybe_unused]] std::size_t bytes_transferred)
{
    if (ec)
    {
        std::cerr << "write: " << ec.message() << std::endl;
        return;
    }

    // Очищаем буфер и читаем следующее сообщение
    _buffer.consume(_buffer.size());
    do_read();
}
