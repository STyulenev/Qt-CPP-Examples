#include <QCoreApplication>

#include <Server.h>

auto main(int argc, char** argv) -> int
{
    QCoreApplication app(argc, argv);
    Server server;

    return server.run(argc, argv) && app.exec();
}
