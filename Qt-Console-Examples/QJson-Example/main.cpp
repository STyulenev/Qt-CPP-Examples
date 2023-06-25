#include <QCoreApplication>
#include <QFile>

#include "JsonFacade.h"

auto main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) -> int
{
    //Q_UNUSED(argc);
    //Q_UNUSED(argv);

    {
        QString jsonString;
        QFile file(":/res/example.json");

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            jsonString = file.readAll();
            file.close();
        } else {
            qDebug() << "file not open";
            return 1;
        }

        JsonModel::JsonFacade facade(jsonString);


        qDebug() << facade.getJsonValueByKey("status").toString();
        qDebug() << facade.getJsonArrayByKey("users");

        JsonModel::UserListJson users = facade.getUserList();
        users.print();
    }

    {
        JsonModel::UserListJson users;

        users.addUser("Mary", "Smith", 18);
        users.addUser("Mary", "Smith", 17);
        users.addUser("Mary", "Smith", 16);
        users.addUser("Mary", "Smith", 19);
        users.sortByAge();

        JsonModel::UserListJson users2;
        users2.addUser("Mary", "Smith", 18);

        JsonModel::UserListJson users3 = users + users2;
        users3.print();

        qDebug() << (users == users2);
        qDebug() << (users != users2);

        users.print();
        users2.print();
    }

    return 0;
}
