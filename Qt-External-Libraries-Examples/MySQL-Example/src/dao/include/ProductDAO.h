#pragma once

#include <QDebug>
#include <QMutex>

#include "Product.h"
#include "ConnectionPool.h"

namespace DAO {

class ProductDAO
{
private:
    std::shared_ptr<Connection> connection;
    QMutex mutex;

public:
    ProductDAO();
    ~ProductDAO();

    auto selectProducts(QList<Entities::Product>& products) -> void;

};

} // namespace DAO
