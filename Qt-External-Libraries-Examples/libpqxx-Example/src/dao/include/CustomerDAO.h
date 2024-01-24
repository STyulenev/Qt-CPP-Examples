#pragma once

#include "Customer.h"
#include <pqxx/pqxx>

class CustomerDAO
{
public:
    CustomerDAO();
    ~CustomerDAO();

    auto selectCustomers(QList<Entities::Customer>& customers) -> void;

private:
    pqxx::connection* connection;

};

