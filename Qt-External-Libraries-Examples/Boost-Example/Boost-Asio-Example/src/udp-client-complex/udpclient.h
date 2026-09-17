#include <boost/asio.hpp>

#include <atomic>
#include <functional>
#include <thread>

class UdpClient
{
public:
    UdpClient() = delete;
    UdpClient(const std::string& host, const std::string& port);
    ~UdpClient();

    void send(const std::string& message);
    void wait();
    void stop();
    void set_on_reply(std::function<void(const std::string&)> cb);

private:
    void start_receive();

    boost::asio::io_context        _io_context;      // Ядро всей асинхронной модели Asio (операции ввода-вывода и очередь событий)
    boost::asio::ip::udp::socket   _socket;          // UDP-сокет для передачи сообщений
    boost::asio::ip::udp::resolver _resolver;        // Преобразователь имени хоста в IP-адрес
    boost::asio::ip::udp::endpoint _server_endpoint; // Адрес получателя
    boost::asio::ip::udp::endpoint _sender_endpoint; // Адресс отправителя

    std::thread _io_thread;
    std::atomic<bool> _is_running;
    std::function<void(const std::string&)> _on_reply;

};
