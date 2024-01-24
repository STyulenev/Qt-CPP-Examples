#pragma once

#include "Product.h"

/*namespace pqxx {
    class connection;
}*/
#include <pqxx/pqxx>

class ProductDAO
{
public:
    ProductDAO();
    ~ProductDAO();

    auto selectProducts(QList<Entities::Product>& products) -> void;

    /*static auto insertProduct(const Entities::Product& Product) -> void;

    static auto updateProduct(const Entities::Product& Product) -> void;*/
private:
    pqxx::connection* connection;

};

