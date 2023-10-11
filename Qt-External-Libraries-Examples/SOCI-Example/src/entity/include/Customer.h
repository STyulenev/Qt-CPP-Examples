#pragma once

#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>

#include <QDebug>

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
    ~Customer() = default;

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

    auto print() -> void;

};

} // namespace Entities

namespace soci {

template<> struct type_conversion<Entities::Customer>
{
    typedef values base_type;

    static void from_base(const values& v, indicator, Entities::Customer& customer);
    static void to_base(const Entities::Customer& customer, values& v, indicator& ind);

};

} // namespace soci
