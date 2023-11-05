#include "Order.h"

#include <QDebug>

namespace Entities {

Order::Order() :
    id(0)
{

}

auto Order::getId() const -> int
{
    return id;
}

auto Order::getCustomer() const -> Customer&
{
    return customer;
}

auto Order::getProduct() const -> Product&
{
    return product;
}

auto Order::getQuantity() const -> int
{
    return quantity;
}

auto Order::getDate() const -> const std::tm&
{
    return date;
}

auto Order::getTime() const -> const std::tm&
{
    return time;
}

auto Order::getDateAsString() const -> QString
{
    return QString("%1-%2-%3").arg(date.tm_mday).arg(1 + date.tm_mon).arg(1900 + date.tm_year);
}

auto Order::getTimeAsString() const -> QString
{
    return QString("%1:%2:%3").arg(time.tm_hour).arg(time.tm_min).arg(time.tm_sec);
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

auto Order::setDate(const std::tm& date) -> void
{
    this->date = date;
}

auto Order::setTime(const std::tm& time) -> void
{
    this->time = time;
}

auto Order::print() -> void
{
    qDebug() << id << product.getName() << date.tm_year; // << date << time;
}

} // namespace Entities

namespace soci {

void type_conversion<Entities::Order>::from_base(const values& v, indicator, Entities::Order& order)
{
    order.setId(v.get<int>("id"));

    order.getProduct().setId(v.get<int>("product_id"));
    order.getProduct().setType(QString::fromStdString(v.get<std::string>("product_type")));
    order.getProduct().setName(QString::fromStdString(v.get<std::string>("product_name")));
    order.getProduct().setManufacturer(QString::fromStdString(v.get<std::string>("manufacturer")));
    order.getProduct().setCount(v.get<int>("product_count"));
    order.getProduct().setPrice(v.get<long long int>("price"));

    order.getCustomer().setId(v.get<int>("customer_id"));
    order.getCustomer().setFirstName(QString::fromStdString(v.get<std::string>("first_name")));
    order.getCustomer().setLastName(QString::fromStdString(v.get<std::string>("last_name")));
    order.getCustomer().setEmail(QString::fromStdString(v.get<std::string>("e_mail")));
    order.getCustomer().setAge(v.get<int>("age"));

    order.setQuantity(v.get<int>("quantity"));
    order.setDate(v.get<std::tm>("order_date"));
    order.setTime(v.get<std::tm>("order_time"));
}

void type_conversion<Entities::Order>::to_base(const Entities::Order& order, values& v, indicator& ind)
{
    v.set("id", order.getId());
    v.set("quantity", order.getQuantity());
    v.set("order_date", order.getDate());
    v.set("order_time", order.getTime());
    v.set("customer_id", order.getCustomer().getId());
    v.set("product_id", order.getProduct().getId());

    ind = i_ok;
}

} // namespace soci
