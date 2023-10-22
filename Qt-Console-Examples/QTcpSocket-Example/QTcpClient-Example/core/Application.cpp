#include <Application.h>

#include "TcpSocket.h"

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
    socket = new Transport::TcpSocket();

    connect(socket, &Transport::TcpSocket::getMessage, this, [](const QString& message) -> void {
        qDebug() << message;
    });

    socket->launch();
    socket->moveToThread(socketThread);
    socketThread->start();

    this->setProperty("TcpSocket", QVariant::fromValue<QObject*>(socket));
}
