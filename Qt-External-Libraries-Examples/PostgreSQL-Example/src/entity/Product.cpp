#include "Product.h"

namespace Entities {

Product::Product()
{

}

Product::~Product()
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

auto Product::getPrice() const -> int
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

auto Product::setPrice(int price) -> void
{
    this->price = price;
}

} // namespace Entities
