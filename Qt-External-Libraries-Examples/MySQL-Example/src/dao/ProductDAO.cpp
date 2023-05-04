#include "ProductDAO.h"

#include <QMutexLocker>
#include <QDebug>

namespace DAO {

ProductDAO::ProductDAO()
{
    connection = ConnectionPool::getPool()->getConnection();
}

ProductDAO::~ProductDAO()
{
    ConnectionPool::getPool()->freeConnection(connection);
}

auto ProductDAO::selectProducts(QList<Entities::Product>& products) -> void
{
    QMutexLocker locker(&mutex);

    if (!connection->query("SELECT Products.id, Products.product_type, Products.product_name, Products.manufacturer, Products.product_count, Products.price "
                           "FROM Products ORDER BY id ASC;")) {
        //qDebug() << connection->getLastError();
    }

    MYSQL_RES* res;
    MYSQL_ROW row;

    res = mysql_use_result(connection->getConnection().get());

    while ((row = mysql_fetch_row(res))) {
        Entities::Product product;

        product.setId(QString::fromLocal8Bit(row[0]).toInt());
        product.setType(QString(row[1]));
        product.setName(QString(row[2]));
        product.setManufacturer(QString(row[3]));
        product.setCount(QString::fromLocal8Bit(row[4]).toInt());
        product.setPrice(QString::fromLocal8Bit(row[5]).toInt());

        products << std::move(product);
    }

    mysql_free_result(res);
}

auto ProductDAO::insertProduct(const Entities::Product& product) -> void
{
    QMutexLocker locker(&mutex);

    QString query = QString("INSERT INTO Products VALUES (default, '%1', '%2', '%3', %4, %5);")
            .arg(product.getType())
            .arg(product.getName())
            .arg(product.getManufacturer())
            .arg(product.getCount())
            .arg(product.getPrice());

    if (!connection->query(query)) {
        //qDebug() << connection->getLastError();
    }
}

} // namespace DAO
