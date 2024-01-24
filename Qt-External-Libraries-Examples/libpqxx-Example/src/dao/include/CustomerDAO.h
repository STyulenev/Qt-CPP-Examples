#pragma once

#include "Customer.h"

/*namespace pqxx {
    class connection;
}*/
#include <pqxx/pqxx>

class CustomerDAO
{
public:
    CustomerDAO();
    ~CustomerDAO();

    auto selectCustomers(QList<Entities::Customer>& Customers) -> void;

    /*static auto insertCustomer(const Entities::Customer& Customer) -> void;

    static auto updateCustomer(const Entities::Customer& Customer) -> void;*/
private:
    pqxx::connection* connection;

};

