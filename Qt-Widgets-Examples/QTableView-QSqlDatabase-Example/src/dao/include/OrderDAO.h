#pragma once

#include <QDebug>
#include <QMutex>

#include "Order.h"
#include "ConnectionPool.h"

namespace DAO {

class OrderDAO
{
private:
    std::shared_ptr<QSqlDatabase> connection;
    std::shared_ptr<QSqlQuery> query;
    QMutex mutex;

public:
    OrderDAO();
    ~OrderDAO();

    auto selectOrders(QList<Entities::Order>& orders) -> void;

};

} // namespace DAO
