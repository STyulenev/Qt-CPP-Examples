#pragma once

#include <QJsonArray>
#include <QJsonObject>

class UserList
{
public:
    UserList();

    auto addUser(QJsonObject& newUser) -> void;

    auto getUserList() -> const QJsonArray&;

    auto getUserForId(int id) -> QJsonObject;

    auto deleteUserForId(int id) -> bool;

private:
    QJsonArray users;
};

