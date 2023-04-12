#pragma once

#include <QDebug>

#include "Customer.h"
#include "Product.h"
#include "Order.h"

class DAO
{
public:
    DAO() = delete;
    DAO(const DAO& other) = delete;
    DAO& operator=(const DAO& other) = delete;
    DAO(DAO&&) = delete;
    DAO& operator=(DAO&&) = delete;
    ~DAO() = delete;

    static auto selectCustomers(QList<Entities::Customer>& customers) -> void;

    static auto selectProducts(QList<Entities::Product>& products) -> void;

    static auto selectOrders(QList<Entities::Order>& orders) -> void;

    static auto insertCustomer(const Entities::Customer& customer) -> void;

    static auto insertProduct(const Entities::Product& product) -> void;

    static auto deleteCustomer(const int id) -> void;

    static auto deleteProduct(const int id) -> void;

    static auto updateCustomer(const Entities::Customer& customer) -> void;

    static auto updateProduct(const Entities::Product& product) -> void;

};

