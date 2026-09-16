#include "tcpserver.h"

#include "session.h"

#include <iostream>

TcpServer::TcpServer(unsigned short port) :
    _io_context(),
    _acceptor(_io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
    _is_running(false)
{

}

TcpServer::~TcpServer()
{
    stop();
}

void TcpServer::start(std::size_t thread_count)
{
    if (_is_running)
    {
        return;
    }

    _is_running = true;

    // work_guard удерживает io_context живым, пока сервер не остановят
    _work_guard.emplace(boost::asio::make_work_guard(_io_context));

    do_accept();

    // Запускаем пул потоков для io_context
    _threads.reserve(thread_count);
    for (std::size_t i = 0; i < thread_count; ++i)
    {
        _threads.emplace_back([this] { _io_context.run(); });
    }

    std::cout << "Server started with " << thread_count << " thread(s).\n";
}

void TcpServer::stop()
{
    if (!_is_running)
    {
        return;
    }

    _is_running = false;

    // Закрываем acceptor — новые соединения не принимаются
    boost::system::error_code ec;
    _acceptor.close(ec);

    // Сбрасываем work_guard, чтобы run() завершился,
    // когда все текущие операции доиграют
    _work_guard.reset();

    // Останавливаем io_context принудительно
    _io_context.stop();

    // Дожидаемся завершения потоков
    for (auto& t : _threads)
    {
        if (t.joinable()) t.join();
    }

    _threads.clear();

    std::cout << "Server stopped.\n";
}

void TcpServer::do_accept()
{
    _acceptor.async_accept(
        [this](const boost::system::error_code& ec, boost::asio::ip::tcp::socket socket) {
            if (!ec)
            {
                std::make_shared<Session>(std::move(socket))->start();
            }

            // Продолжаем принимать, если не остановлены
            if (_is_running && ec != boost::asio::error::operation_aborted)
            {
                do_accept();
            }
        });
}
