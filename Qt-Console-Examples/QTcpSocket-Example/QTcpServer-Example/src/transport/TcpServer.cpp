#include "TcpServer.h"

#include <QHostAddress>

namespace Transport {

TcpServer::TcpServer(QObject* parent) :
    AbstractServer(parent)
{

}

TcpServer::~TcpServer()
{

}

void TcpServer::launch()
{
    server = new QTcpServer(this);

    server->listen(QHostAddress::Any, 4242);
    connect(server, &QTcpServer::newConnection, this, &TcpServer::onNewConnection, Qt::QueuedConnection);
}

void TcpServer::onNewConnection()
{
    QTcpSocket* clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &TcpServer::onReadyRead);
    connect(clientSocket, &QTcpSocket::stateChanged, this, &TcpServer::onSocketStateChanged);

    socketsList.push_back(clientSocket);
    for (QTcpSocket* socket : socketsList) {
        socket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString() + " connected to server !\n"));
    }
}

void TcpServer::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState) {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        disconnect(sender, &QTcpSocket::readyRead, this, &TcpServer::onReadyRead);
        disconnect(sender, &QTcpSocket::stateChanged, this, &TcpServer::onSocketStateChanged);
        socketsList.removeOne(sender);
    }
}

void TcpServer::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();

    const QString message = QString(datas);

    emit getMessage(message);
}

} // namespace Transport
