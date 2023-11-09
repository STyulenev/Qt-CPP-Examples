#include "Product.h"

#include <QDebug>

namespace Entities {

Product::Product() :
    id(0)
{

}

auto Product::getId() const -> int
{
    return id;
}

auto Product::getType() const -> const QString&
{
    return type;
}

auto Product::getName() const -> const QString&
{
    return name;
}

auto Product::getManufacturer() const -> const QString&
{
    return manufacturer;
}

auto Product::getCount() const -> int
{
    return count;
}

auto Product::getPrice() const -> long long int
{
    return price;
}

auto Product::setId(int id) -> void
{
    this->id = id;
}

auto Product::setType(const QString& type) -> void
{
    this->type = type;
}

auto Product::setName(const QString &name) -> void
{
    this->name = name;
}

auto Product::setManufacturer(const QString& manufacturer) -> void
{
    this->manufacturer = manufacturer;
}

auto Product::setCount(int count) -> void
{
    this->count = count;
}

auto Product::setPrice(long long int price) -> void
{
    this->price = price;
}

auto Product::print() -> void
{
    qDebug() << id << type << name;
}

} // namespace Entities

namespace soci {

void type_conversion<Entities::Product>::from_base(const values& v, indicator, Entities::Product& product)
{
    product.setId(v.get<int>("id"));
    product.setType(QString::fromStdString(v.get<std::string>("product_type")));
    product.setName(QString::fromStdString(v.get<std::string>("product_name")));
    product.setManufacturer(QString::fromStdString(v.get<std::string>("manufacturer")));
    product.setCount(v.get<int>("product_count"));
    product.setPrice(v.get<long long int>("price"));
}

void type_conversion<Entities::Product>::to_base(const Entities::Product& product, values& v, indicator& ind)
{
    v.set("id", product.getId());
    v.set("product_type", product.getType().toStdString());
    v.set("product_name", product.getName().toStdString());
    v.set("manufacturer", product.getManufacturer().toStdString());
    v.set("product_count", product.getCount());
    v.set("price", product.getPrice());
    ind = i_ok;
}

} // namespace soci
