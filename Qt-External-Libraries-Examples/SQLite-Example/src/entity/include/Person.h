#pragma once

#include <QString>
#include <QDebug>

namespace Entities {

class Person
{
private:
    int id;
    QString firstName;
    QString lastName;
    int age;

public:
    Person();
    ~Person();

    int getId() const;
    const QString& getFirstName() const;
    const QString& getLastName() const;
    int getAge() const;

    void setId(int id);
    void setFirstName(const QString& firstName);
    void setLastName(const QString& lastName);
    void setAge(int age);

    void print() const;

};

} // namespace Entities
