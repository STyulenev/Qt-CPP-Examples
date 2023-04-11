#pragma once

#include "Customer.h"
#include "Product.h"

namespace Entities {

class Order
{
private:
    int id;
    Customer customer;
    Product product;
    int quantity;
    QString order_date;
    QString order_time;

public:
    Order();
    ~Order();

    int getId() const;
    void setId(int newId);
    const Customer &getCustomer() const;
    void setCustomer(const Customer &newCustomer);
    const Product &getProduct() const;
    void setProduct(const Product &newProduct);
    int getQuantity() const;
    void setQuantity(int newQuantity);
    const QString &getOrder_date() const;
    void setOrder_date(const QString &newOrder_date);
    const QString &getOrder_time() const;
    void setOrder_time(const QString &newOrder_time);
};

} // namespace Entities

