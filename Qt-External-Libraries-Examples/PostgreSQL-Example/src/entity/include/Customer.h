#pragma once

#include "QString"

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
    virtual ~Customer();

    int getId() const;
    void setId(int newId);
    const QString &getFirstName() const;
    void setFirstName(const QString &newFirstName);
    const QString &getLastName() const;
    void setLastName(const QString &newLastName);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    int getAge() const;
    void setAge(int newAge);
};

} // namespace Entities
