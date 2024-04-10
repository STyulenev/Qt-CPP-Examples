#include <Application.h>

namespace Core {

Application::Application(int& argc, char** argv) :
    QCoreApplication(argc, argv)
{
    setOrganizationName("Organization");
    setOrganizationDomain("organization.com");
}

Application::~Application()
{
    if (server) {
        serverThread->quit();
        serverThread->wait();

        delete serverThread;
        serverThread = nullptr;

        delete server;
    }
}

auto Application::launch() -> void
{
    try {
        server = new Transport::HttpServer();
    } catch (...) {
        // ...
    }

    if (server) {
        serverThread = new QThread();

        server->moveToThread(serverThread);
        serverThread->start();
    }
}

} // namespace Core
