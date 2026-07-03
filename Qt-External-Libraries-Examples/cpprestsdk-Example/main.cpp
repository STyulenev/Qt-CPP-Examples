#include <QCoreApplication>

#include "site/web_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    app::site::WebServer webServer;

    webServer.Initialize();

    if (!webServer.IsInitialized())
    {
        return -1;
    }

    webServer.Start();

    return a.exec();
}
