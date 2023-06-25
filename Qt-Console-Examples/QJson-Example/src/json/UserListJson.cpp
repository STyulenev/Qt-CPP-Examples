#include "UserListJson.h"

#include <QDebug>

#include <algorithm>

inline auto swap(QJsonValueRef valueOne, QJsonValueRef valueTwo) -> void
{
    QJsonValue temp(valueOne);
    valueOne = QJsonValue(valueTwo);
    valueTwo = temp;
}

namespace JsonModel {

UserListJson::UserListJson()
{
    // ...
}

UserListJson::UserListJson(QJsonArray&& users)
{
    this->users = std::move(users);
    // or std::copy(users.begin(), users.end(), std::back_inserter(this->users));
}

UserListJson::~UserListJson()
{
    // ...
}

auto UserListJson::addUser(const QString& firstName, const QString& lastName, const int age) -> void
{
    QJsonObject newObject;

    newObject["first_name"] = firstName;
    newObject["last_name"]  = lastName;
    newObject["age"]        = age;

    users.append(std::move(newObject));
}

auto UserListJson::getFirstName(const int id) const -> QString
{
    return users.at(id).toObject()["first_name"].toString();
}

auto UserListJson::getLastName(const int id) const -> QString
{
    return users.at(id).toObject()["last_name"].toString();
}

auto UserListJson::getAge(const int id) const -> int
{
    return users.at(id).toObject()["age"].toInt();
}

auto UserListJson::setFirstName(const int id, const QString& firstName) -> void
{
    QJsonObject temp = users.at(id).toObject();
    temp["first_name"] = firstName;

    users.replace(id, temp);
}

auto UserListJson::setLastName(const int id, const QString& lastName) -> void
{
    QJsonObject temp = users.at(id).toObject();
    temp["last_name"] = lastName;

    users.replace(id, temp);
}

auto UserListJson::setAge(const int id, const int age) -> void
{
    QJsonObject temp = users.at(id).toObject();
    temp["age"] = age;

    users.replace(id, temp);
}

auto UserListJson::sortByFirstName() -> void
{
    std::sort(users.begin(), users.end(), [](const QJsonValue& valueOne, const QJsonValue& valueTwo) {
        return valueOne.toObject()["first_name"].toString() < valueTwo.toObject()["first_name"].toString();
    });
}

auto UserListJson::sortByLastName() -> void
{
    std::sort(users.begin(), users.end(), [](const QJsonValue& valueOne, const QJsonValue& valueTwo) {
        return valueOne.toObject()["last_name"].toString() < valueTwo.toObject()["last_name"].toString();
    });
}

auto UserListJson::sortByAge() -> void
{
    std::sort(users.begin(), users.end(), [](const QJsonValue& valueOne, const QJsonValue& valueTwo) {
        return valueOne.toObject()["age"].toInt() < valueTwo.toObject()["age"].toInt();
    });
}

auto UserListJson::clearArray() -> void
{
    while (users.count()) {
        users.pop_back();
    }
}

auto UserListJson::deleteForId(const int id) -> void
{
    if (id > -1 && id < users.size())
        users.removeAt(id);
}

auto UserListJson::serializeToStringData() -> QString
{
    QJsonDocument doc;
    doc.setArray(users);

    QString dataToString(doc.toJson());

    return dataToString;
}

auto UserListJson::serializeFromStringData(const QString& data) -> void
{
    this->clearArray();

    this->users = QJsonDocument::fromJson(data.toUtf8()).array();
}

auto UserListJson::print() -> void
{
    QString dataToString = this->serializeToStringData();

    qDebug() << dataToString.toStdString().c_str();

    //or just qDebug() << users;
}

auto UserListJson::length() const -> int
{
    return users.size();
}

auto UserListJson::at(const int id) const  -> QJsonObject
{
    return users.at(id).toObject();
}

auto UserListJson::operator+(const UserListJson& twoList) -> UserListJson
{
    for (int i = 0; i < twoList.length(); ++i) {
        this->users.append(twoList.at(i));
    }

    return *this;
}

auto UserListJson::operator==(const UserListJson& twoList) const -> bool
{
    if (this->length() != twoList.length()) {
        return false;
    } else {
        return std::equal(users.begin(), users.end(), twoList.users.begin());
    }
}

auto UserListJson::operator!=(const UserListJson& twoList) const -> bool
{
    if (this->length() != twoList.length()) {
        return true;
    } else {
        return std::equal(users.begin(), users.end(), twoList.users.begin());
    }
}

auto UserListJson::operator=(const UserListJson& twoList) -> UserListJson
{
    this->clearArray();

    std::copy(twoList.users.begin(), twoList.users.end(), std::back_inserter(this->users));

    return *this;
}

} // namespace JsonModel
