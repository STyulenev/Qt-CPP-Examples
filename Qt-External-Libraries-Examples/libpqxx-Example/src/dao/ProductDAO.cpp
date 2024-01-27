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
    } catch (std::exception const& error) {
        qDebug() << "error: " << error.what();
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
        qDebug() << "error: " << error.what();
    }
}

auto ProductDAO::insertProduct(const Entities::Product& product) -> void
{
    pqxx::work tx (*connection);

    const QString query = QString("INSERT INTO Products VALUES (default, '%1', '%2', '%3', %4, %5);")
                              .arg(product.getType())
                              .arg(product.getName())
                              .arg(product.getManufacturer())
                              .arg(product.getCount())
                              .arg(product.getPrice());

    tx.exec(query.toStdString());
    tx.commit();
}

auto ProductDAO::updateProduct(const Entities::Product& product) -> void
{
    pqxx::work tx (*connection);

    const QString query = QString("UPDATE Products SET product_type = '%1', product_name = '%2', "
                                  "manufacturer = '%3', product_count = %4, price = %5 WHERE id = %6;")
                              .arg(product.getType())
                              .arg(product.getName())
                              .arg(product.getManufacturer())
                              .arg(product.getCount())
                              .arg(product.getPrice())
                              .arg(product.getId());

    tx.exec(query.toStdString());
    tx.commit();
}
