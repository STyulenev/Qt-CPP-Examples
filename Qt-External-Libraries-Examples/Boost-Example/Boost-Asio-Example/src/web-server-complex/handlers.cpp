#include "handlers.h"

#include <iostream>

Handlers::Handlers(tcp::socket&& socket) :
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

        beast::flat_buffer buffer;
        http::read(_socket, buffer, _request);

        _response.version(_request.version());

        switch (_request.method())
        {
        case http::verb::get:
            get();
            break;
        case http::verb::post:
            post();
            break;
        case http::verb::put:
        case http::verb::delete_:
        // ...
        default:
            _response.result(http::status::method_not_allowed);
            _response.body() = "{\"status\": \"error\", \"method\": \"unknown\"}";
            break;
        }

        _response.prepare_payload();

        http::write(_socket, _response);

        beast::error_code ec;
        _socket.shutdown(tcp::socket::shutdown_send, ec);
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
    _response.result(http::status::ok);
    _response.set(http::field::server, "Boost.Asio localhost");
    _response.set(http::field::content_type, "text/plain");
    _response.body() = "{\"status\": \"ok\", \"method\": \"get\"}";
}

void Handlers::post()
{
    _response.result(http::status::ok);
    _response.set(http::field::server, "Boost.Asio localhost");
    _response.set(http::field::content_type, "text/plain");
    _response.body() = "{\"status\": \"ok\", \"method\": \"post\"}";
}
