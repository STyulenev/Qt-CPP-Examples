#pragma once

#include <QDebug>
#include <QMutex>

#include "Product.h"
#include "ConnectionPool.h"

namespace DAO {

class ProductDAO
{
private:
    std::shared_ptr<QSqlDatabase> connection;
    std::shared_ptr<QSqlQuery> query;
    QMutex mutex;

public:
    ProductDAO();
    ~ProductDAO();

    auto selectProducts(QList<Entities::Product>& products) -> void;

    auto insertProduct(const Entities::Product& product) -> void;

    auto deleteProduct(const int id) -> void;

    auto updateProduct(const Entities::Product& product) -> void;

};

} // namespace DAO
