#pragma once

#include <QDebug>

#include "Customer.h"
#include "Product.h"
#include "Order.h"

class DAO
{
private:
    static DAO* self;

    DAO();
    DAO(const DAO&);
    auto operator=(DAO&) -> DAO&;

    [[nodiscard("Необходимо проверять значение для доступа к БД")]]
    auto openDB() noexcept -> bool;

    auto closeDB() noexcept -> void;

public:
    static DAO* getConnection();

    [[nodiscard("Необходимо проверять значение при изменения данных доступа к БД")]]
    auto reconnection(const QString hostName, const int port, const QString dataBaseName, const QString userName, const QString password) -> bool;

    auto selectCustomers(QList<Entities::Customer>& customers) const -> void;

    auto selectProducts(QList<Entities::Product>& products) const -> void;

    auto selectOrders(QList<Entities::Order>& orders) const -> void;

    auto insertCustomer(const Entities::Customer& customer) const -> void;

    auto insertProduct(const Entities::Product& product) const -> void;

    auto deleteCustomer(const int id) const -> void;

    auto deleteProduct(const int id) const -> void;

    auto updateCustomer(const Entities::Customer& customer) const -> void;

    auto updateProduct(const Entities::Product& product) const -> void;

};

