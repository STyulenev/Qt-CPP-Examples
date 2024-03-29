#pragma once

#include "Product.h"

namespace pqxx {
    class connection;
}

class ProductDAO
{
public:
    ProductDAO();
    ~ProductDAO();

    auto selectProducts(QList<Entities::Product>& products) -> void;

    /*!
     * \brief insertProducts method
     * \code
     * Entities::Product product; // id ~ 6
     * product.setType("Phone");
     * product.setName("iPhone 19");
     * product.setManufacturer("Gorizont Company");
     * product.setCount(5);
     * product.setPrice(79000);
     * productDAO->insertProduct(product);
     * \endcode
     * \param new product
     */
    auto insertProduct(const Entities::Product& product) -> void;

    auto updateProduct(const Entities::Product& product) -> void;

    auto deleteProduct(const int id) -> void;

private:
    std::shared_ptr<pqxx::connection> connection;

};

