#pragma once

#include "Order.h"

namespace pqxx {
    class connection;
}

class OrderDAO
{
public:
    OrderDAO();
    ~OrderDAO();

    auto selectOrders(QList<Entities::Order>& orders) -> void;

private:
    std::shared_ptr<pqxx::connection> connection;

};

