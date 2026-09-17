#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
    std::string host          = "localhost";
    const std::string port    = "8080";

    try
    {
        boost::asio::io_context ioc;

        boost::asio::ip::tcp::resolver resolver{ioc};
        boost::beast::websocket::stream<boost::asio::ip::tcp::socket> ws{ioc};

        const auto results = resolver.resolve(host, port);
        auto ep = boost::asio::connect(ws.next_layer(), results);

        // Формируем Host-заголовок для handshake
        host += ':' + std::to_string(ep.port());

        // Устанавливаем User-Agent
        ws.set_option(boost::beast::websocket::stream_base::decorator(
            [](boost::beast::websocket::request_type& req) {
                req.set(boost::beast::http::field::user_agent, "Boost.Beast WebSocket Client");
            }));

        ws.handshake(host, "/"); // Рукопожатие к 'localhost:8080/'

        std::cout << "Enter message: ";
        char request[1024];
        std::cin.getline(request, 1024);
        std::string message(request);
        message.push_back('\n');

        ws.write(boost::asio::buffer(std::string(message)));

        // Читаем ответ
        boost::beast::flat_buffer buffer;
        ws.read(buffer);

        std::cout << "Received: " << boost::beast::make_printable(buffer.data()) << std::endl;

        ws.close(boost::beast::websocket::close_code::normal);
    }
    catch (const std::exception& error)
    {
        std::cerr << "Exception: " << error.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << "\n";
        return 1;
    }

    return 0;
}
