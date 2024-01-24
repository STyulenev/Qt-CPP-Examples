#pragma once

#include "Product.h"
#include <pqxx/pqxx>

class ProductDAO
{
public:
    ProductDAO();
    ~ProductDAO();

    auto selectProducts(QList<Entities::Product>& products) -> void;

private:
    pqxx::connection* connection;

};

