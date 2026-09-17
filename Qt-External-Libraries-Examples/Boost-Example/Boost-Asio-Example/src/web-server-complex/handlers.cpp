#include "handlers.h"

#include <iostream>

Handlers::Handlers(boost::asio::ip::tcp::socket&& socket) :
    _socket(std::move(socket))
{
    process();
}

void Handlers::process()
{
    try
    {
        if (!_socket.is_open())
        {
            std::cerr << "Socket has closed\n";
        }

        boost::beast::flat_buffer buffer;
        boost::beast::http::read(_socket, buffer, _request);

        _response.version(_request.version());

        switch (_request.method())
        {
        case boost::beast::http::verb::get:
            get();
            break;
        case boost::beast::http::verb::post:
            post();
            break;
        case boost::beast::http::verb::put:
        case boost::beast::http::verb::delete_:
        // ...
        default:
            _response.result(boost::beast::http::status::method_not_allowed);
            _response.body() = "{\"status\": \"error\", \"method\": \"unknown\"}";
            break;
        }

        _response.prepare_payload();

        boost::beast::http::write(_socket, _response);

        boost::beast::error_code ec;
        _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ec);
    }
    catch (const std::exception& error)
    {
        std::cerr << "Session error: " << error.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Unknown error in session\n";
    }
}

void Handlers::get()
{
    _response.result(boost::beast::http::status::ok);
    _response.set(boost::beast::http::field::server, "Boost.Asio localhost");
    _response.set(boost::beast::http::field::content_type, "text/plain");
    _response.body() = "{\"status\": \"ok\", \"method\": \"get\"}";
}

void Handlers::post()
{
    _response.result(boost::beast::http::status::ok);
    _response.set(boost::beast::http::field::server, "Boost.Asio localhost");
    _response.set(boost::beast::http::field::content_type, "text/plain");
    _response.body() = "{\"status\": \"ok\", \"method\": \"post\"}";
}
