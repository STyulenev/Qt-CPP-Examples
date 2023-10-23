#include <Application.h>

#include "UdpSocket.h"

Application::Application(int& argc, char** argv) :
    QApplication(argc, argv)
{
    setOrganizationName("Organization");
    setOrganizationDomain("organization.com");
}

Application::~Application()
{
    socketThread->quit();
    socketThread->wait();

    delete socketThread;
    socketThread = nullptr;

    delete socket;
}

auto Application::launch() -> void
{
    socketThread = new QThread();
    socket = new Transport::UdpSocket();

    connect(socket, &Transport::UdpSocket::getMessage, this, [](const QString& message) -> void {
        qDebug() << message;
    });

    socket->launch();
    socket->moveToThread(socketThread);
    socketThread->start();

    this->setProperty("UdpSocket", QVariant::fromValue<QObject*>(socket));
}
