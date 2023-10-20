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

void Application::launch()
{
    socketThread = new QThread();
    socket = new Transport::TcpSocket();
    socket->launch();
    socket->moveToThread(socketThread);
    socketThread->start();

    this->setProperty("TcpSocket", QVariant::fromValue<QObject*>(socket));
}
