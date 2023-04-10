#include "Product.h"

namespace Entities {

Product::Product()
{

}

Product::~Product()
{

}

int Product::getId() const
{
    return id;
}

void Product::setId(int newId)
{
    id = newId;
}

const QString &Product::getProduct_type() const
{
    return product_type;
}

void Product::setProduct_type(const QString &newProduct_type)
{
    product_type = newProduct_type;
}

const QString &Product::getProduct_name() const
{
    return product_name;
}

void Product::setProduct_name(const QString &newProduct_name)
{
    product_name = newProduct_name;
}

const QString &Product::getManufacturer() const
{
    return manufacturer;
}

void Product::setManufacturer(const QString &newManufacturer)
{
    manufacturer = newManufacturer;
}

int Product::getProduct_count() const
{
    return product_count;
}

void Product::setProduct_count(int newProduct_count)
{
    product_count = newProduct_count;
}

int Product::getPrice() const
{
    return price;
}

void Product::setPrice(int newPrice)
{
    price = newPrice;
}

} // namespace Entities
