#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>

class Handlers
{
public:
    Handlers(boost::asio::ip::tcp::socket&& socket);

private:
    void process();

    void get();
    void post();

private:
    boost::asio::ip::tcp::socket                                  _socket;
    boost::beast::http::request<boost::beast::http::string_body>  _request;
    boost::beast::http::response<boost::beast::http::string_body> _response;

};
