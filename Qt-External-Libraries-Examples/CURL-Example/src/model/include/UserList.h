#pragma once

#include <QJsonArray>
#include <QJsonObject>

class UserList
{
private:
    QJsonArray users;

public:
    UserList();
    UserList(QString json);

    ~UserList();

    auto addUser(QJsonObject& newUser) -> void;

    auto getUserList() -> const QJsonArray&;

    auto getUserForId(int id) -> QJsonObject;

    auto deleteUserForId(int id) -> bool;

};

