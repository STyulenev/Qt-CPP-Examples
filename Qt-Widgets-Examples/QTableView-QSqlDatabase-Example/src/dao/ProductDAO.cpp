#include "ProductDAO.h"

#include <QMutexLocker>
#include <QDebug>

namespace DAO {

ProductDAO::ProductDAO(QObject* parent) :
    QObject(parent)
{
    connection = ConnectionPool::getPool()->getConnection();
    query = std::make_shared<QSqlQuery>(*connection.get());

    if (connection->open() && connection.get()->isValid()) {
        if (!connection.get()->driver()->subscribeToNotification("insert_products_notification"))
            qDebug() << connection.get()->driver()->lastError().databaseText();

        if (!connection.get()->driver()->subscribeToNotification("delete_products_notification"))
            qDebug() << connection.get()->driver()->lastError().databaseText();

        if (!connection.get()->driver()->subscribeToNotification("update_products_notification"))
            qDebug() << connection.get()->driver()->lastError().databaseText();

        connect(connection.get()->driver(), QOverload<const QString&, QSqlDriver::NotificationSource, const QVariant&>::of(&QSqlDriver::notification), this,
                [this](const QString& name, [[maybe_unused]] QSqlDriver::NotificationSource source, const QVariant& payload) {
                    qDebug() << "notify:" << name << ", payload:" << payload.toString();

                    emit productsTableChanged();
                });
    } else {
        qDebug() << "Error:" << connection.get()->lastError();
    }
}

ProductDAO::~ProductDAO()
{
    connection->close();
    ConnectionPool::getPool()->freeConnection(connection);
}

auto ProductDAO::selectProducts(QList<Entities::Product>& products) -> void
{
    QMutexLocker locker(&mutex);

    bool result = query->exec("SELECT * FROM Products ORDER BY id ASC;");

    if (result) {
        QSqlRecord record = query->record();
        const int idIndex           = record.indexOf("id");
        const int typeIndex         = record.indexOf("product_type");
        const int nameIndex         = record.indexOf("product_name");
        const int manufacturerIndex = record.indexOf("manufacturer");
        const int countIndex        = record.indexOf("product_count");
        const int priceIndex        = record.indexOf("price");

        while (query->next()) {
            Entities::Product product;

            product.setId(query->value(idIndex).toInt());
            product.setType(query->value(typeIndex).toString());
            product.setName(query->value(nameIndex).toString());
            product.setManufacturer(query->value(manufacturerIndex).toString());
            product.setCount(query->value(countIndex).toInt());
            product.setPrice(query->value(priceIndex).toInt());

            products << std::move(product);
        }
    } else {
        qDebug() << "Error:" << query->lastError().text();
    }

    query->clear();
}

auto ProductDAO::insertProduct(const Entities::Product& product) -> void
{
    QMutexLocker locker(&mutex);

    query->prepare("INSERT INTO Products VALUES (default, :product_type, :product_name, :manufacturer, :product_count, :price);");

    query->bindValue(":product_type",  product.getType());
    query->bindValue(":product_name",  product.getName());
    query->bindValue(":manufacturer",  product.getManufacturer());
    query->bindValue(":product_count", product.getCount());
    query->bindValue(":price",         product.getPrice());

    bool result = query->exec();

    if (result) {
        qDebug() << "Error:" << query->lastError().text();
    }

    query->clear();
}

auto ProductDAO::deleteProduct(const int id) -> void
{
    QMutexLocker locker(&mutex);

    query->prepare("DELETE FROM Products WHERE id = :id");
    query->bindValue(":id", id);

    bool result = query->exec();

    if (result) {
        qDebug() << "Error:" << query->lastError().text();
    }

    query->clear();
}

auto ProductDAO::updateProduct(const Entities::Product& product) -> void
{
    query->prepare("UPDATE Products SET product_type = :product_type, product_name = :product_name, "
                   "manufacturer = :manufacturer, product_count = :product_count, price = :price WHERE id = :id;");

    query->bindValue(":product_type",  product.getType());
    query->bindValue(":product_name",  product.getName());
    query->bindValue(":manufacturer",  product.getManufacturer());
    query->bindValue(":product_count", product.getCount());
    query->bindValue(":price",         product.getPrice());
    query->bindValue(":id",            product.getId());

    bool result = query->exec();

    if (result) {
        qDebug() << "Error:" << query->lastError().text();
    }

    query->clear();
}

} // namespace DAO
