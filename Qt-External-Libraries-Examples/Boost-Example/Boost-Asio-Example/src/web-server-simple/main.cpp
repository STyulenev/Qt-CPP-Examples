#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>
#include <thread>

namespace asio  = boost::asio;
namespace beast = boost::beast;
namespace http  = beast::http;

using tcp = boost::asio::ip::tcp;

// Обработчик одного HTTP-соединения
void do_session(tcp::socket socket)
{
    try
    {
        beast::flat_buffer buffer;
        http::request<http::string_body> request;

        // Читаем HTTP-запрос
        http::read(socket, buffer, request);

        // Формируем ответ
        http::response<http::string_body> response{
            http::status::ok, request.version()
        };

        response.set(http::field::server, "Boost.Asio Example");
        response.set(http::field::content_type, "text/html");

        switch (request.method())
        {
        case http::verb::get:
            response.body() = "{\"status\": \"ok\"}";
            break;
        case http::verb::post:
            response.body() = "{\"status\": \"ok\"}";
            break;
        case http::verb::put:
            response.body() = "{\"status\": \"ok\"}";
            break;
        case http::verb::delete_:
            response.body() = "{\"status\": \"ok\"}";
            break;
        default:
            response.result(http::status::method_not_allowed);
            response.body() = "{\"status\": \"error\"}";
            break;
        }

        response.prepare_payload();

        // Отправляем ответ
        http::write(socket, response);

        // Корректно закрываем соединение
        beast::error_code ec;
        socket.shutdown(tcp::socket::shutdown_send, ec);
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << "\n";
    }
}

int main()
{
    try
    {
        const auto address = asio::ip::make_address("0.0.0.0");
        const auto port = static_cast<unsigned short>(8080);

        asio::io_context ioc{1};
        tcp::acceptor acceptor{ioc, {address, port}};

        std::cout << "Server running on http://localhost:8080\n";

        for (;;)
        {
            // Принимаем входящее соединение
            tcp::socket socket{ioc};
            acceptor.accept(socket);

            // Обрабатываем соединение в отдельном потоке
            std::thread{std::move(do_session), std::move(socket)}.detach();
        }
    }
    catch (const std::exception& error)
    {
        std::cerr << "Fatal error: " << error.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << "\n";
    }

    return 0;
}
