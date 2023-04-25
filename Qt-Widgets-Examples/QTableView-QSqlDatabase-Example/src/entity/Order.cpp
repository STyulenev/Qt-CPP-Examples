#include "Order.h"

namespace Entities {

Order::Order() :
    id(0)
{

}

Order::~Order()
{

}

auto Order::getId() const -> int
{
    return id;
}

auto Order::getCustomer() const -> const Customer&
{
    return customer;
}

auto Order::getProduct() const -> const Product&
{
    return product;
}

auto Order::getQuantity() const -> int
{
    return quantity;
}

auto Order::getDate() const -> const QString&
{
    return date;
}

auto Order::getTime() const -> const QString&
{
    return time;
}

auto Order::setId(int id) -> void
{
    this->id = id;
}

auto Order::setCustomer(const Customer& customer) -> void
{
    this->customer = customer;
}

auto Order::setProduct(const Product& product) -> void
{
    this->product = product;
}

auto Order::setQuantity(int quantity) -> void
{
    this->quantity = quantity;
}

auto Order::setDate(const QString& date) -> void
{
    this->date = date;
}

auto Order::setTime(const QString& time) -> void
{
    this->time = time;
}

} // namespace Entities
