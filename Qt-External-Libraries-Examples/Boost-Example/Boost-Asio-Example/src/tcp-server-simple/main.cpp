#include <iostream>
#include <boost/asio.hpp>

int main()
{
    try
    {
        // Ядро всей асинхронной модели Asio (операции ввода-вывода и очередь событий)
        boost::asio::io_context io_context;

        // Слушаем порт 8080 на всех интерфейсах IPv4
        boost::asio::ip::tcp::acceptor acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8080));
        std::cout << "Server listening on port 8080...\n";

        for (;;)
        {
            boost::asio::ip::tcp::socket socket(io_context);
            acceptor.accept(socket);  // Блокирующее ожидание клиента

            std::cout << "Client connected: " << socket.remote_endpoint() << "\n";

            char data[1024];
            boost::system::error_code error;

            // Читаем данные от клиента
            size_t length = socket.read_some(boost::asio::buffer(data), error);

            if (!error)
            {
                std::cout << "Received: " << std::string(data, length) << "\n";

                // Отправляем то же самое обратно
                boost::asio::write(socket, boost::asio::buffer(data, length));
            }
        }
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
