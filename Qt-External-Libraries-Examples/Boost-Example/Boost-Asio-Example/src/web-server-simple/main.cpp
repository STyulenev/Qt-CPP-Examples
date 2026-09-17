#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include <iostream>
#include <thread>

// Обработчик одного HTTP-соединения
void do_session(boost::asio::ip::tcp::socket socket)
{
    try
    {
        boost::beast::flat_buffer buffer;
        boost::beast::http::request<boost::beast::http::string_body> request;

        // Читаем HTTP-запрос
        boost::beast::http::read(socket, buffer, request);

        // Формируем ответ
        boost::beast::http::response<boost::beast::http::string_body> response{
            boost::beast::http::status::ok, request.version()
        };

        response.set(boost::beast::http::field::server, "Boost.Asio Example");
        response.set(boost::beast::http::field::content_type, "text/html");

        switch (request.method())
        {
        case boost::beast::http::verb::get:
            response.body() = "{\"status\": \"ok\"}";
            break;
        case boost::beast::http::verb::post:
            response.body() = "{\"status\": \"ok\"}";
            break;
        case boost::beast::http::verb::put:
            response.body() = "{\"status\": \"ok\"}";
            break;
        case boost::beast::http::verb::delete_:
            response.body() = "{\"status\": \"ok\"}";
            break;
        default:
            response.result(boost::beast::http::status::method_not_allowed);
            response.body() = "{\"status\": \"error\"}";
            break;
        }

        response.prepare_payload();

        // Отправляем ответ
        boost::beast::http::write(socket, response);

        // Корректно закрываем соединение
        boost::beast::error_code ec;
        socket.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ec);
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << "\n";
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
        const auto address = boost::asio::ip::make_address("0.0.0.0");
        const unsigned short port = 8080;

        boost::asio::io_context ioc{1};
        boost::asio::ip::tcp::acceptor acceptor{ioc, {address, port}};

        std::cout << "Server running on http://localhost:8080\n";

        for (;;)
        {
            // Принимаем входящее соединение
            boost::asio::ip::tcp::socket socket{ioc};
            acceptor.accept(socket);

            // Обрабатываем соединение в отдельном потоке
            std::thread{std::move(do_session), std::move(socket)}.detach();
        }
    }
    catch (const std::exception& error)
    {
        std::cerr << "Fatal error: " << error.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << "\n";
    }

    return 0;
}
