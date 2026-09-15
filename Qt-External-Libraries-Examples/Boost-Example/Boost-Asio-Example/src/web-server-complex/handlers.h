#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace asio = boost::asio;
namespace beast = boost::beast;
namespace http = beast::http;
using tcp = asio::ip::tcp;

class Handlers
{
public:
    Handlers(tcp::socket&& socket);

private:
    void process();

    void get();
    void post();

private:
    tcp::socket                       _socket;
    http::request<http::string_body>  _request;
    http::response<http::string_body> _response;

};
