#pragma once

#include "QString"

namespace Entities {

class Product
{
private:
    int     id;
    QString type;
    QString name;
    QString manufacturer;
    int     count;
    int     price;

public:
    Product();
    ~Product();

    auto getId() const -> int;
    auto getType() const -> const QString&;
    auto getName() const -> const QString&;
    auto getManufacturer() const -> const QString&;
    auto getCount() const -> int;
    auto getPrice() const -> int;

    auto setId(int newId) -> void;
    auto setType(const QString& type) -> void;
    auto setName(const QString& name) -> void;
    auto setManufacturer(const QString& manufacturer) -> void;
    auto setCount(int count) -> void;
    auto setPrice(int price) -> void;
};

} // namespace Entities
