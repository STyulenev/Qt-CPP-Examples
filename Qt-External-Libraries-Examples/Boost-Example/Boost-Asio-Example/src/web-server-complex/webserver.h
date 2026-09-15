#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include <atomic>
#include <thread>

namespace asio = boost::asio;
namespace beast = boost::beast;
namespace http = beast::http;
using tcp = asio::ip::tcp;

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

    asio::io_context io_context_;
    tcp::acceptor acceptor_;
    std::thread io_thread_;
    std::atomic<bool> running_;

    std::vector<std::thread> session_threads_;
};
