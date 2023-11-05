#pragma once

#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>

#include <QString>

namespace Entities {

class Product
{
private:
    int           id;
    QString       type;
    QString       name;
    QString       manufacturer;
    int           count;
    long long int price;

public:
    Product();
    ~Product() = default;

    auto getId() const -> int;
    auto getType() const -> const QString&;
    auto getName() const -> const QString&;
    auto getManufacturer() const -> const QString&;
    auto getCount() const -> int;
    auto getPrice() const -> long long int;

    auto setId(int newId) -> void;
    auto setType(const QString& type) -> void;
    auto setName(const QString& name) -> void;
    auto setManufacturer(const QString& manufacturer) -> void;
    auto setCount(int count) -> void;
    auto setPrice(long long int price) -> void;

    auto print() -> void;
};

} // namespace Entities

namespace soci {

template<> struct type_conversion<Entities::Product>
{
    typedef values base_type;

    static void from_base(const values& v, indicator, Entities::Product& product);
    static void to_base(const Entities::Product& product, values& v, indicator& ind);

};

} // namespace soci
