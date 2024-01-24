#pragma once

#include "Order.h"
#include <pqxx/pqxx>

class OrderDAO
{
public:
    OrderDAO();
    ~OrderDAO();

    auto selectOrders(QList<Entities::Order>& orders) -> void;

private:
    pqxx::connection* connection;

};

