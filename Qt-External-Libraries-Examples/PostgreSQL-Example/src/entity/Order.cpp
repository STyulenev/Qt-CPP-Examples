#include "Order.h"

namespace Entities {

Order::Order()
{

}

Order::~Order()
{

}

int Order::getId() const
{
    return id;
}

void Order::setId(int newId)
{
    id = newId;
}

const Customer &Order::getCustomer() const
{
    return customer;
}

void Order::setCustomer(const Customer &newCustomer)
{
    customer = newCustomer;
}

const Product &Order::getProduct() const
{
    return product;
}

void Order::setProduct(const Product &newProduct)
{
    product = newProduct;
}

int Order::getQuantity() const
{
    return quantity;
}

void Order::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

const QString &Order::getOrder_date() const
{
    return order_date;
}

void Order::setOrder_date(const QString &newOrder_date)
{
    order_date = newOrder_date;
}

const QString &Order::getOrder_time() const
{
    return order_time;
}

void Order::setOrder_time(const QString &newOrder_time)
{
    order_time = newOrder_time;
}




} // namespace Entities
