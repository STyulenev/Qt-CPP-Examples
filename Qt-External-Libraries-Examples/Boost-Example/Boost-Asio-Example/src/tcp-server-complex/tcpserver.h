#pragma once

#include <boost/asio.hpp>

#include <thread>
#include <vector>
#include <atomic>

// Неблокирующий TCP-сервер
class TcpServer
{
public:
    TcpServer() = delete;
    explicit TcpServer(unsigned short port);
    ~TcpServer();

    void start(std::size_t thread_count = 1);
    void stop();

private:
    void do_accept();

    boost::asio::io_context        _io_context; // Ядро всей асинхронной модели Asio (операции ввода-вывода и очередь событий)
    boost::asio::ip::tcp::acceptor _acceptor;   // Слушающий сокет сервера для принятия входящих TCP-соединений

    std::optional<boost::asio::executor_work_guard<boost::asio::io_context::executor_type>> _work_guard; // Флаг для io_context, чтобы сервер продолжал работать

    std::vector<std::thread> _threads;
    std::atomic<bool>        _is_running;

};
