#pragma once

#include <QString>

namespace Entities {

class Customer
{
private:
    int     id;
    QString firstName;
    QString lastName;
    QString email;
    int     age;

public:
    Customer();
    ~Customer();

    auto getId() const -> int;
    auto getFirstName() const -> const QString&;
    auto getLastName() const -> const QString&;
    auto getEmail() const -> const QString&;
    auto getAge() const -> int;

    auto setId(int id) -> void;
    auto setFirstName(const QString& firstName) -> void;
    auto setLastName(const QString& lastName) -> void;
    auto setEmail(const QString& email) -> void;
    auto setAge(int age) -> void;
};

} // namespace Entities
