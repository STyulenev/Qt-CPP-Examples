#include "session.h"

#include <iostream>

Session::Session(boost::asio::ip::tcp::socket socket) :
    _socket(std::move(socket)),
    _strand(boost::asio::make_strand(_socket.get_executor()))
{

}

void Session::start()
{
    do_read();
}

void Session::do_read()
{
    auto self = shared_from_this();

     _socket.async_read_some(boost::asio::buffer(_data),
        boost::asio::bind_executor(_strand,
        [this, self](const boost::system::error_code& ec, std::size_t length)
        {

            std::cout << "Received: " << std::string(_data, length) << "\n";

            if (!ec)
            {
                do_write(length);
            }
            else
            {
                // error
            }
        })
    );
}

void Session::do_write(std::size_t length)
{
    auto self = shared_from_this();

    boost::asio::async_write(_socket, boost::asio::buffer(_data, length),
        boost::asio::bind_executor(_strand,
        [this, self](const boost::system::error_code& ec, [[maybe_unused]] std::size_t length) {
           if (!ec)
            {
               do_read();
            }
            else
            {
               // error
            }
       })
    );
}
