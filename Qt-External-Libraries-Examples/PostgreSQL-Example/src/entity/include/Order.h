#pragma once

#include "Customer.h"
#include "Product.h"

namespace Entities {

class Order
{
private:
    int      id;
    Customer customer;
    Product  product;
    int      quantity;
    QString  date;
    QString  time;

public:
    Order();
    ~Order();

    auto getId() const -> int;
    auto getCustomer() const -> const Customer&;
    auto getProduct() const -> const Product&;
    auto getQuantity() const -> int;
    auto getDate() const -> const QString&;
    auto getTime() const -> const QString&;

    auto setId(int id) -> void;
    auto setCustomer(const Customer& customer) -> void;
    auto setProduct(const Product& product) -> void;
    auto setQuantity(int quantity) -> void;
    auto setDate(const QString& date) -> void;
    auto setTime(const QString& time) -> void;
};

} // namespace Entities

