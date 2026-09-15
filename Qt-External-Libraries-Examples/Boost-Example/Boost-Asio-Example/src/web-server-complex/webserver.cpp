#include "webserver.h"
#include "handlers.h"

#include <iostream>

WebServer::WebServer(unsigned short port) :
    io_context_(),
    acceptor_(io_context_, tcp::endpoint(tcp::v4(), port)),
    running_(false)
{
    std::cout << "Server configured for port: " << port << "\n";
}

WebServer::~WebServer()
{
    stop();
}

void WebServer::start()
{
    if (running_)
    {
        return;
    }

    running_ = true;

    // Поток для io_context
    io_thread_ = std::thread([this]() {
        // Эмулируем "работу", чтобы run() не завершился сразу
        auto work_guard = asio::make_work_guard(io_context_);

        // Запускаем асинхронный приём
        start_accept();

        // run() будет блокироваться, пока есть работа
        io_context_.run();
    });
}

void WebServer::stop()
{
    if (!running_)
    {
        return;
    }

    running_ = false;

    io_context_.stop();

    if (io_thread_.joinable())
    {
        io_thread_.join();
    }

    for (auto& t : session_threads_)
    {
        if (t.joinable()) {
            t.join();
        }
    }
    session_threads_.clear();

    std::cout << "Server stopped\n";
}

void WebServer::start_accept()
{
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec)
            {
                session_threads_.emplace_back([socket = std::move(socket)]() mutable {
                    Handlers(std::move(socket));
                });
            }

            if (running_)
            {
                start_accept();
            }
        });
}
