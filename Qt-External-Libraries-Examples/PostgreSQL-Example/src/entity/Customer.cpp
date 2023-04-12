#include "Customer.h"

namespace Entities {

Customer::Customer()
{

}

Customer::~Customer()
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

} // namespace Entities
