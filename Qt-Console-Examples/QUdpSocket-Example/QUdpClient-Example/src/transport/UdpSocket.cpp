#include "UdpSocket.h"

#include <QDebug>
#include <QHostAddress>

namespace Transport {

UdpSocket::UdpSocket(QObject* parent) :
    AbstractSocket(parent)
{

}

UdpSocket::~UdpSocket()
{

}

void UdpSocket::launch()
{
    socket = new QUdpSocket(this);

    //socket->connectToHost(QHostAddress("127.0.0.1"), 4242);

    QObject::connect(socket, &QUdpSocket::readyRead, this, &UdpSocket::onReadyRead);
    connect(this, &AbstractSocket::write, this, &UdpSocket::onReadyWrite);
    // Поскольку клиент также получает данные, отправленные сервером, клиент также должен связать локальный IP-адрес и номер порта
    if (socket->bind(QHostAddress("127.0.0.1"), 5000) > 0)
        qDebug() << "bind sucess";
}

void UdpSocket::onReadyWrite(const QByteArray& message)
{
    //socket->write(message);


    QHostAddress serverAddress = QHostAddress("127.0.0.1");
    if (socket->writeDatagram(message.data(), message.size(),serverAddress,5000) > 0) {
        qDebug()<<"write is ok";
    } else {
     // Вы можете вызвать функцию error (), чтобы проверить причину неудачного связывания
        qDebug()<<socket->error();
        qDebug()<<"write is failed";
    }

}

void UdpSocket::onReadyRead()
{
    QByteArray array;
    // pendingDatagramSize - размер первого сообщения, ожидающего чтения. Функция resize нормализует размер массива в соответствии с размером параметра.
    // Введите в array.data () данные, которые не превышают размер array.size (), а array.data () возвращает указатель на расположение данных, хранящихся в байтовом массиве
    while (socket->hasPendingDatagrams()) {
        array.resize(socket->pendingDatagramSize());
        socket->readDatagram(array.data(), array.size());
        qDebug() << array.data();
    }

    emit getMessage(array.data());
}

} // namespace Transport
