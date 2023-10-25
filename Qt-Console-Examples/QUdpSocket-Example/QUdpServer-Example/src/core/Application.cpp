#include <Application.h>

#include "UdpServer.h"

Application::Application(int& argc, char** argv) :
    QCoreApplication(argc, argv)
{
    setOrganizationName("Organization");
    setOrganizationDomain("organization.com");
}

Application::~Application()
{
    serverThread->quit();
    serverThread->wait();

    delete serverThread;
    serverThread = nullptr;

    delete server;
}

void Application::launch()
{
    serverThread = new QThread();
    server = new Transport::UdpServer();

    connect(server, &Transport::UdpServer::getMessage, this, [](const QString& message) -> void {
        qDebug() << message;
    });

    server->launch();
    server->moveToThread(serverThread);
    serverThread->start();

    // if need be
    // this->setProperty("...", QVariant::fromValue<QObject*>(...));
}
