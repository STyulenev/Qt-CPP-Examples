#include <QCoreApplication>
#include "NetworkManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    NetworkManager networkManager;

    networkManager.getTime();
    networkManager.postUsers();
    networkManager.getUsers();

    return app.exec();
}
