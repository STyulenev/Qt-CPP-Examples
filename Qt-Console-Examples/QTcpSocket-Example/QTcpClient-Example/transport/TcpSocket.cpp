#include "TcpSocket.h"

#include <QHostAddress>

namespace Transport {

TcpSocket::TcpSocket(QObject* parent) :
    AbstractSocket(parent)
{

}

TcpSocket::~TcpSocket()
{

}

auto TcpSocket::launch() -> void
{
    socket = new QTcpSocket(this);

    socket->connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(socket, &QTcpSocket::readyRead, this, &TcpSocket::onReadyRead);
    connect(this, &AbstractSocket::write, this, &TcpSocket::onReadyWrite);
}

auto TcpSocket::onReadyWrite(const QByteArray& message) -> void
{
    socket->write(message);
}

auto TcpSocket::onReadyRead() -> void
{
    QByteArray datas = socket->readAll();
    const QString message = QString(datas);

    emit getMessage(message);
}

} // namespace Transport
