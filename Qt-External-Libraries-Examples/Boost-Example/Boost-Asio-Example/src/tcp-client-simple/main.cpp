#include <iostream>
#include <boost/asio.hpp>

int main()
{
    try
    {
        // Ядро всей асинхронной модели Asio (операции ввода-вывода и очередь событий)
        boost::asio::io_context io_context;

        // Подключаемся к localhost:8080
        boost::asio::ip::tcp::socket socket(io_context);
        socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080));

        std::cout << "Connected to server.\n";

        std::cout << "Enter message: ";
        char request[1024];
        std::cin.getline(request, 1024);

        // Отправляем сообщение
        boost::asio::write(socket, boost::asio::buffer(request));

        // Читаем ответ
        char reply[1024];
        boost::system::error_code error;
        size_t length = socket.read_some(boost::asio::buffer(reply), error);

        if (!error)
        {
            std::cout << "Server replied: " << std::string(reply, length) << "\n";
        }
    }
    catch (const std::exception& error)
    {
        std::cerr << "Exception: " << error.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown error\n";
        return 1;
    }

    return 0;
}
