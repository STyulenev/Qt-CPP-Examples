#include "Person.h"

namespace Models {

Person::Person() :
    id(0),
    age(0)
{

}

Person::~Person()
{

}

int Person::getId() const
{
    return id;
}

const QString& Person::getFirstName() const
{
    return firstName;
}

const QString& Person::getLastName() const
{
    return lastName;
}

int Person::getAge() const
{
    return age;
}

void Person::setId(int id)
{
    this->id = id;
}

void Person::setFirstName(const QString& firstName)
{
    this->firstName = firstName;
}

void Person::setLastName(const QString& lastName)
{
    this->lastName = lastName;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::print() const
{
    qDebug() << id << firstName << lastName << age;
}

} // namespace Models
