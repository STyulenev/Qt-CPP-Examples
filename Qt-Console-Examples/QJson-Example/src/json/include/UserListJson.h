#pragma once

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

namespace JsonModel {

/*!
 * \brief The UserListJson class
 * \details
 * Struct:
 * 1 - [first_name] type QString
 * 2 - [last_name] type QString
 * 3 - [age] type int
 * \todo
 * auto operator+=(const UserListJson& twoList) -> UserListJson&;
 * auto operator-=(const UserListJson& twoList) -> UserListJson&;
 */
class UserListJson
{
private:
    QJsonArray users;

public:
    UserListJson();
    UserListJson(QJsonArray&& users);

    ~UserListJson();

    auto addUser(const QString& firstName, const QString& lastName, const int age) -> void;

    auto getFirstName(const int id) const -> QString;
    auto getLastName(const int id) const -> QString;
    auto getAge(const int id) const -> int;

    auto setFirstName(const int id, const QString& firstName) -> void;
    auto setLastName(const int id, const QString& lastName) -> void;
    auto setAge(const int id, const int age) -> void;

    auto sortByFirstName() -> void;
    auto sortByLastName() -> void;
    auto sortByAge() -> void;

    auto clearArray() -> void;

    auto deleteForId(const int id) -> void;

    auto serializeToStringData() -> QString;

    auto serializeFromStringData(const QString& data) -> void;

    auto print() -> void;

    auto length() const -> int;

    auto at(const int id) const -> QJsonObject;

    auto operator+(const UserListJson& twoList) -> UserListJson;
    auto operator==(const UserListJson& twoList) const -> bool;
    auto operator!=(const UserListJson& twoList) const -> bool;
    auto operator=(const UserListJson& twoList) -> UserListJson;
};

} // namespace JsonModel
