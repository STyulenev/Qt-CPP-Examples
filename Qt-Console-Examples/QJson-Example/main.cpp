#include <QCoreApplication>
#include <User.h>

int main(int argc, char* argv[])
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

    return 0;
}
