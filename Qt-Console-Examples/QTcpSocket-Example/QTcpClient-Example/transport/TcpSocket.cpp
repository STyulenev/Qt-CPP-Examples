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

void TcpSocket::launch()
{
    socket = new QTcpSocket(this);

    socket->connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(socket, &QTcpSocket::readyRead, this, &TcpSocket::onReadyRead);
    connect(this, &AbstractSocket::write, this, &TcpSocket::onReadyWrite);
}

void TcpSocket::onReadyWrite(const QByteArray& message)
{
    socket->write(message);
}

void TcpSocket::onReadyRead()
{
    QByteArray datas = socket->readAll();
    const QString message = QString(datas);

    emit getMessage(message);
}

} // namespace Transport
