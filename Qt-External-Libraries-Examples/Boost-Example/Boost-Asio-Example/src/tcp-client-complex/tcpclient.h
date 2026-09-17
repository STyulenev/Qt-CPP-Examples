#pragma once

#include <boost/asio.hpp>

#include <thread>
#include <atomic>

// Блокирующий слиент
class TcpClient
{
public:
    TcpClient();
    ~TcpClient();

    // Синхронное подключение. Блокирует до установки соединения или ошибки.
    bool connectSync(const std::string& host, const std::string& port);

    // Синхронная отправка. Блокирует до отправки всех данных.
    bool sendSync(const std::string& message);

    // Синхронное чтение. Блокирует до получения данных или ошибки.
    // Возвращает пустую строку при ошибке.
    std::string receiveSync(std::size_t max_length = 1024);

    // Синхронное чтение до определённого разделителя (например, '\n')
    std::string receiveUntil(const std::string& delimiter);

    void stop();

    bool isOpen() const;

private:
    boost::asio::io_context        _io_context; // Ядро всей асинхронной модели Asio (операции ввода-вывода и очередь событий)
    boost::asio::ip::tcp::socket   _socket;     // TCP-сокет для передачи сообщений
    boost::asio::ip::tcp::resolver _resolver;   // Преобразователь имени хоста в IP-адрес

    std::thread       _thread;
    std::atomic<bool> _is_running;

};
