#pragma once

#include <boost/asio.hpp>
#include <thread>
#include <atomic>

class UdpServer
{
public:
    UdpServer() = delete;
    explicit UdpServer(unsigned short port);
    ~UdpServer();

    void start();
    void stop();

private:
    void start_receive();

private:
    boost::asio::io_context        _io_context; // Ядро всей асинхронной модели Asio (операции ввода-вывода и очередь событий)
    boost::asio::ip::udp::socket   _socket;     // UDP-сокет с конкретным портом

    std::thread       _io_thread;
    std::atomic<bool> _running;

};
