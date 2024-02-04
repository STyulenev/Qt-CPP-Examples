#include <QCoreApplication>

#include "NetworkManager.h"

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    NetworkManager networkManager;

    networkManager.getTime();
    networkManager.postUsers();
    networkManager.getUsers();

    return app.exec();
}
