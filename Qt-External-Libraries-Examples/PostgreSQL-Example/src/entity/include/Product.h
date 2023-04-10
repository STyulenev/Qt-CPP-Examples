#pragma once

#include "QString"

namespace Entities {

class Product
{
private:
    int     id;
    QString product_type;
    QString product_name;
    QString manufacturer;
    int     product_count;
    int     price;

public:
    Product();
    ~Product();

    int getId() const;
    void setId(int newId);
    const QString &getProduct_type() const;
    void setProduct_type(const QString &newProduct_type);
    const QString &getProduct_name() const;
    void setProduct_name(const QString &newProduct_name);
    const QString &getManufacturer() const;
    void setManufacturer(const QString &newManufacturer);
    int getProduct_count() const;
    void setProduct_count(int newProduct_count);
    int getPrice() const;
    void setPrice(int newPrice);
};

} // namespace Entities
