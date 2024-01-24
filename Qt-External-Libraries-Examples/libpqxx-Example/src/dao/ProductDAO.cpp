#include "ProductDAO.h"

#include <QDebug>


ProductDAO::ProductDAO()
{
    try {
        connection = new pqxx::connection {
            "host='localhost' "
            "port='5432' "
            "dbname='test_db' "
            "user='postgres' "
            "password='tyulenev' "
        };

        qDebug() << "Connected to" << connection->dbname();

        /**/

    } catch (std::exception const& error) {
        qDebug() << "ERROR: " << error.what() << '\n';
    }
}

ProductDAO::~ProductDAO()
{
    delete connection;
}

void ProductDAO::selectProducts(QList<Entities::Product>& products)
{
    try {
        pqxx::work tx (*connection);

        for (auto [id, product_type, product_name, manufacturer, product_count, price] :
             tx.query<int, std::string, std::string, std::string, int, int>("SELECT * FROM Products ORDER BY id ASC;")) {
            Entities::Product product;

            product.setId(id);
            product.setType(product_type.c_str());
            product.setName(product_name.c_str());
            product.setManufacturer(manufacturer.c_str());
            product.setCount(product_count);
            product.setPrice(price);

            products << std::move(product);
        }
    } catch (std::exception const& error) {
        qDebug() << "ERROR: " << error.what() << '\n';
    }
}
