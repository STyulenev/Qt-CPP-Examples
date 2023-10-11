#pragma once

#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>

#include <QDebug>

//using namespace std;
//using namespace soci;

//CREATE TABLE IF NOT EXISTS Customers
//    (
//        id         SERIAL PRIMARY KEY,
//        first_name CHARACTER VARYING(30) NOT NULL,
//        last_name  CHARACTER VARYING(30) NOT NULL,
//        e_mail     CHARACTER VARYING(50) UNIQUE,
//        age        INTEGER DEFAULT 18 CHECK(age > 0 AND age < 100)
//        );

struct Customer
{
    int id;
    std::string first_name;
    std::string last_name;
    std::string e_mail;
    int age;

    void print() {
        qDebug() << id << first_name << last_name;
    }
};

namespace soci
{

template<> struct type_conversion<Customer>
{
    typedef values base_type;

    static void from_base(const values& v, indicator, Customer& customer)
    {
        customer.id = v.get<int>("id");
        customer.first_name = v.get<std::string>("first_name");
        customer.last_name = v.get<std::string>("last_name");

        customer.e_mail = v.get<std::string>("e_mail");
        customer.age = v.get<int>("age");
    }

    static void to_base(const Customer& customer, values& v, indicator& ind)
    {
        v.set("id", customer.id);
        v.set("first_name", customer.first_name);
        v.set("last_name", customer.last_name);
        v.set("e_mail", customer.e_mail);
        v.set("age", customer.age);
        ind = i_ok;
    }
};

} // namespace soci

