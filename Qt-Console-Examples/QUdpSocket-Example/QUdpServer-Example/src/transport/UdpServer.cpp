#include "UdpServer.h"

#include <QDebug>
#include <QHostAddress>

namespace Transport {

UdpServer::UdpServer(QObject* parent) :
    AbstractServer(parent)
{

}

UdpServer::~UdpServer()
{

}

void UdpServer::launch()
{
    server = new QUdpSocket(this);

    if (server->bind(QHostAddress("127.0.0.1"), 5000) > 0) {
        qDebug()<<"bind sucess";
    } else {
        qDebug() << server->error();
        qDebug() << "bind failed";

        //emit error
    }

    // Сервер использует сигналы и слоты для контроля поступления данных
    connect(server, &QUdpSocket::readyRead, this, &UdpServer::onReadyRead);
    //connect(server, &QUdpSocket::errorOccurred, this, ...
}

void UdpServer::onReadyRead()
{
    QByteArray array;
    QHostAddress address;
    quint16 port;
    array.resize(server->bytesAvailable()); // Установить размер пространства в соответствии с читаемыми данными
    // Читаем данные, получаем IP-адрес клиента и номер порта
    int tmp = server->readDatagram(array.data(),array.size(),&address,&port);
    qDebug() << array.data();

    if (tmp > 0) {
        emit getMessage(array.data());

        // if host == localehost then will be loop
        // server->writeDatagram(array.data(), QHostAddress(address), 5000);
    }
}

} // namespace Transport
