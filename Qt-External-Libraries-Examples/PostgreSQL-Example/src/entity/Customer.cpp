#include "Customer.h"

namespace Entities {

Customer::Customer()
{

}

Customer::~Customer()
{

}

int Customer::getId() const
{
    return id;
}

void Customer::setId(int newId)
{
    id = newId;
}

const QString& Customer::getFirstName() const
{
    return firstName;
}

void Customer::setFirstName(const QString& newFirstName)
{
    firstName = newFirstName;
}

const QString& Customer::getLastName() const
{
    return lastName;
}

void Customer::setLastName(const QString& newLastName)
{
    lastName = newLastName;
}

const QString &Customer::getEmail() const
{
    return email;
}

void Customer::setEmail(const QString& newEmail)
{
    email = newEmail;
}

int Customer::getAge() const
{
    return age;
}

void Customer::setAge(int newAge)
{
    age = newAge;
}

} // namespace Entities
