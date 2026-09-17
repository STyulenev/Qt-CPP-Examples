#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include <atomic>
#include <thread>

class WebServer
{
public:
    WebServer() = delete;
    explicit WebServer(unsigned short port);
    ~WebServer();

    void start();
    void stop();

private:
    void start_accept();

private:
    boost::asio::io_context        _io_context;
    boost::asio::ip::tcp::acceptor _acceptor;

    std::thread       _io_thread;
    std::atomic<bool> _is_running;

    std::vector<std::thread> _session_threads;

};
