#pragma once

#include "Customer.h"
#include "Product.h"
#include "Order.h"

class DAO
{
public:
    DAO();

    static auto getCustomersList(QList<Entities::Customer>& customers) -> void;

    static auto getProductsList(QList<Entities::Product>& products) -> void;

    static auto getOrdersList(QList<Entities::Order>& orders) -> void;
};

