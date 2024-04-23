#pragma once

#include <QJsonArray>
#include <QJsonObject>

namespace Models {

class UserList
{
public:
    UserList();
    ~UserList() = default;

    auto addUser(QJsonObject& newUser) -> void;

    auto getUserList() -> const QJsonArray&;

    auto getUserForId(int id) -> QJsonObject;

    auto deleteUserForId(int id) -> bool;

private:
    QJsonArray users;

};

} // namespace Models
