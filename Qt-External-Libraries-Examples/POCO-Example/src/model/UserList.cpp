#include "UserList.h"

namespace Models {

UserList::UserList()
{

}

auto UserList::addUser(QJsonObject& newUser) -> void
{
    users.append(std::move(newUser));
}

auto UserList::getUserList() -> const QJsonArray&
{
    return this->users;
}

auto UserList::getUserForId(int id) -> QJsonObject
{
    if (id > this->users.size() - 1 || id < 0) {
        return this->users.last().toObject();
    } else {
        return this->users.at(id).toObject();
    }
}

auto UserList::deleteUserForId(int id) -> bool
{
    if (id < this->users.size() - 1 || id >= 0) {
        this->users.removeAt(id);
        return true;
    }

    return false;
}

} // namespace Models
