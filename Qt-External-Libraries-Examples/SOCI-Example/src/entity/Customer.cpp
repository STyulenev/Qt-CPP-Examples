#include "Customer.h"

namespace Entities {

Customer::Customer() :
    id(0)
{

}

auto Customer::getId() const -> int
{
    return id;
}

auto Customer::getFirstName() const -> const QString&
{
    return firstName;
}

auto Customer::getLastName() const -> const QString&
{
    return lastName;
}

auto Customer::getEmail() const -> const QString&
{
    return email;
}

auto Customer::getAge() const -> int
{
    return age;
}

auto Customer::setId(int id) -> void
{
    this->id = id;
}

auto Customer::setFirstName(const QString& firstName) -> void
{
    this->firstName = firstName;
}

auto Customer::setLastName(const QString& lastName) -> void
{
    this->lastName = lastName;
}

auto Customer::setEmail(const QString& email) -> void
{
    this->email = email;
}

auto Customer::setAge(int age) -> void
{
    this->age = age;
}

auto Customer::print() -> void
{
    qDebug() << id << firstName << lastName;
}

} // namespace Entities

namespace soci {

void type_conversion<Entities::Customer>::from_base(const values& v, indicator, Entities::Customer& customer)
{
    customer.setId(v.get<int>("id"));
    customer.setFirstName(QString::fromStdString(v.get<std::string>("first_name")));
    customer.setLastName(QString::fromStdString(v.get<std::string>("last_name")));
    customer.setEmail(QString::fromStdString(v.get<std::string>("e_mail")));
    customer.setAge(v.get<int>("age"));
}

void type_conversion<Entities::Customer>::to_base(const Entities::Customer& customer, values& v, indicator& ind)
{
    v.set("id", customer.getId());
    v.set("first_name", customer.getFirstName().toStdString());
    v.set("last_name", customer.getLastName().toStdString());
    v.set("e_mail", customer.getEmail().toStdString());
    v.set("age", customer.getAge());
    ind = i_ok;
}

} // namespace soci
