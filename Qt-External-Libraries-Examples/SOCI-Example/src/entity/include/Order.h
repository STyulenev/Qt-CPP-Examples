#pragma once

#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>

#include <QDebug>

#include "Customer.h"
#include "Product.h"

#include <ctime>

namespace Entities {

class Order
{
private:
    int      id;
    Customer customer;
    Product  product;
    int      quantity;
    std::tm  date;
    std::tm  time;

public:
    Order();
    ~Order() = default;

    auto getId() const -> int;
    auto getCustomer() -> Customer&;
    auto getProduct() -> Product&;
    auto getQuantity() const -> int;
    auto getDate() const -> const std::tm&;
    auto getTime() const -> const std::tm&;

    auto setId(int id) -> void;
    auto setCustomer(const Customer& customer) -> void;
    auto setProduct(const Product& product) -> void;
    auto setQuantity(int quantity) -> void;
    auto setDate(const std::tm& date) -> void;
    auto setTime(const std::tm& time) -> void;

    auto print() -> void;
};

} // namespace Entities

namespace soci {

template<> struct type_conversion<Entities::Order>
{
    typedef values base_type;

    static void from_base(const values& v, indicator, Entities::Order& order);
    static void to_base(const Entities::Order& order, values& v, indicator& ind);

};

} // namespace soci
