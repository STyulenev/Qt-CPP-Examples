#include "tcpclient.h"

#include <iostream>

TcpClient::TcpClient() :
    _io_context(),
    _socket(_io_context),
    _resolver(_io_context),
    _is_running(false)
{

}

TcpClient::~TcpClient()
{
    stop();
}

bool TcpClient::connectSync(const std::string& host, const std::string& port)
{
    boost::system::error_code ec;

    auto results = _resolver.resolve(host, port, ec);

    if (ec)
    {
        std::cerr << "Resolve error: " << ec.message() << '\n';
        return false;
    }

    boost::asio::connect(_socket, results, ec);

    if (ec)
    {
        std::cerr << "Connect error: " << ec.message() << '\n';
        return false;
    }

    std::cout << "Connected (sync) to " << host << ":" << port << '\n';
    return true;
}

bool TcpClient::sendSync(const std::string& message)
{
    boost::system::error_code ec;
    boost::asio::write(_socket, boost::asio::buffer(message), ec);

    if (ec)
    {
        std::cerr << "Write error: " << ec.message() << '\n';
        return false;
    }

    return true;
}

std::string TcpClient::receiveSync(std::size_t max_length)
{
    std::array<char, 1024> buf;
    std::size_t n = std::min(max_length, buf.size());

    boost::system::error_code ec;
    std::size_t length = _socket.read_some(boost::asio::buffer(buf, n), ec);

    if (ec)
    {
        std::cerr << "Read error: " << ec.message() << '\n';
        return {};
    }

    return std::string(buf.data(), length);
}

std::string TcpClient::receiveUntil(const std::string& delimiter)
{
    boost::system::error_code ec;
    boost::asio::streambuf buf;

    std::size_t length = boost::asio::read_until(_socket, buf, delimiter, ec);

    if (ec)
    {
        std::cerr << "Read error: " << ec.message() << '\n';
        return {};
    }

    std::string data(boost::asio::buffers_begin(buf.data()), boost::asio::buffers_begin(buf.data()) + length);

    buf.consume(length);

    return data;
}

void TcpClient::stop()
{
    boost::system::error_code ec;
    _socket.close(ec);

    if (_is_running)
    {
        _is_running = false;
        _io_context.stop();

        if (_thread.joinable())
        {
            _thread.join();
        }
    }
}

bool TcpClient::isOpen() const
{
    return _socket.is_open();
}
