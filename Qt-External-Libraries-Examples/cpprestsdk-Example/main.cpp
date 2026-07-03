#include <QCoreApplication>

#include "site/web_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    app::site::WebServer webServer;

    if (webServer.initialize())
    {
        webServer.start();
    }

    if (!webServer.isInitialized())
    {
        return -1;
    }

    return a.exec();
}
