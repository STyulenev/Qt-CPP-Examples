#include "listener.h"
#include "session.h"

#include <iostream>

#include <boost/asio/strand.hpp>

Listener::Listener(boost::asio::io_context& ioc, boost::asio::ip::tcp::endpoint endpoint) :
    _io_context(ioc),
    _acceptor(boost::asio::make_strand(ioc))
{
    boost::beast::error_code ec;

    _acceptor.open(endpoint.protocol(), ec);
    if (ec)
    {
        std::cerr << "open: " << ec.message() << '\n';
        return;
    }

    _acceptor.set_option(boost::asio::socket_base::reuse_address(true), ec);

    if (ec)
    {
        std::cerr << "set_option: " << ec.message() << '\n';
        return;
    }

    _acceptor.bind(endpoint, ec);

    if (ec)
    {
        std::cerr << "bind: " << ec.message() << '\n';
        return;
    }

    _acceptor.listen(boost::asio::socket_base::max_listen_connections, ec);

    if (ec)
    {
        std::cerr << "listen: " << ec.message() << '\n';
        return;
    }
}

void Listener::run()
{
    do_accept();
}

void Listener::do_accept()
{
    _acceptor.async_accept(
        boost::asio::make_strand(_io_context),
        boost::beast::bind_front_handler(&Listener::on_accept, shared_from_this()));
}

void Listener::on_accept(boost::beast::error_code ec, boost::asio::ip::tcp::socket socket)
{
    if (ec)
    {
        std::cerr << "accept: " << ec.message() << '\n';
    } else
    {
        std::make_shared<Session>(std::move(socket))->run();
    }

    do_accept();
}
