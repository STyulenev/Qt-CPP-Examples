#pragma once

#include "Precompiled.h"

class QXORM_EXAMPLE_DLL_EXPORT Customer
{
public:
    int     id;
    QString firstName;
    QString lastName;
    QString email;
    int     age;

    Customer() : id(0) { ; }
    virtual ~Customer() { ; }
};

QX_REGISTER_PRIMARY_KEY(Customer, int)
QX_REGISTER_HPP_QXORM_EXAMPLE(Customer, qx::trait::no_base_class_defined, 0)

typedef std::shared_ptr<Customer> Customer_ptr;
typedef QVector<Customer_ptr>     ListCustomer;
