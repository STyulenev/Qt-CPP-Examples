#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

enum
{
    max_length = 1024
};

void server(boost::asio::io_context& io_context, unsigned short port)
{
    // Создаём простой блокирующий сокет для сервера: localhost:8080
    udp::socket sock(io_context, udp::endpoint(udp::v4(), port));

    for (;;)
    {
        char data[max_length];
        udp::endpoint sender_endpoint;

        // Блокирующее получение данных. sender_endpoint заполнится адресом клиента.
        size_t length = sock.receive_from(boost::asio::buffer(data, max_length), sender_endpoint);

        std::cout << "Obtained data: " << data << "\n";

        // Отправляем те же данные обратно клиенту
        sock.send_to(boost::asio::buffer(data, length), sender_endpoint);
    }
}

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_context io_context;
        server(io_context, 8080);
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
