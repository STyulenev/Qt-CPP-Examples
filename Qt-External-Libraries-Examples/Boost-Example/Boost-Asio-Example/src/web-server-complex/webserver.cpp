#include "webserver.h"
#include "handlers.h"

#include <iostream>

WebServer::WebServer(unsigned short port) :
    _io_context(),
    _acceptor(_io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
    _is_running(false)
{
    std::cout << "Server configured for port: " << port << "\n";
}

WebServer::~WebServer()
{
    stop();
}

void WebServer::start()
{
    if (_is_running)
    {
        return;
    }

    _is_running = true;

    // Поток для io_context
    _io_thread = std::thread([this]() {
        // Эмулируем "работу", чтобы run() не завершился сразу
        auto work_guard = boost::asio::make_work_guard(_io_context);

        // Запускаем асинхронный приём
        start_accept();

        // run() будет блокироваться, пока есть работа
        _io_context.run();
    });
}

void WebServer::stop()
{
    if (!_is_running)
    {
        return;
    }

    _is_running = false;

    _io_context.stop();

    if (_io_thread.joinable())
    {
        _io_thread.join();
    }

    for (auto& t : _session_threads)
    {
        if (t.joinable()) {
            t.join();
        }
    }
    _session_threads.clear();

    std::cout << "Server stopped\n";
}

void WebServer::start_accept()
{
    _acceptor.async_accept(
        [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
            if (!ec)
            {
                _session_threads.emplace_back([socket = std::move(socket)]() mutable {
                    Handlers(std::move(socket));
                });
            }

            if (_is_running)
            {
                start_accept();
            }
        });
}
