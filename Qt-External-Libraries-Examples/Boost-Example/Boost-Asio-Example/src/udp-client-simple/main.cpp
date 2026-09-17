#include <boost/asio.hpp>

#include <iostream>

enum
{
    max_length = 1024
};

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_context io_context;

        // Сокет клиента 8081, сервера 8080
        boost::asio::ip::udp::socket s(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8081));

        // Заполняем данные для отправки на GET http://localhost:8080
        boost::asio::ip::udp::resolver resolver(io_context);
        boost::asio::ip::udp::endpoint endpoint = *resolver.resolve(boost::asio::ip::udp::v4(), "localhost", "8080").begin();

        std::cout << "Enter message: ";
        char request[max_length];
        std::cin.getline(request, max_length);
        size_t request_length = std::strlen(request);

        // Отправляем данные на сервер
        s.send_to(boost::asio::buffer(request, request_length), endpoint);

        // Ждём ответ
        char reply[max_length];
        boost::asio::ip::udp::endpoint sender_endpoint;
        size_t reply_length = s.receive_from(boost::asio::buffer(reply, max_length), sender_endpoint);

        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
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
