#pragma once

#include <QMutex>

#include "Order.h"
#include "ConnectionPool.h"

namespace DAO {

class OrderDAO : public QObject
{
    Q_OBJECT

private:
    std::shared_ptr<QSqlDatabase> connection;
    std::shared_ptr<QSqlQuery> query;
    QMutex mutex;

public:
    explicit OrderDAO(QObject* parent = nullptr);
    ~OrderDAO();

    auto selectOrders(QList<Entities::Order>& orders) -> void;

};

} // namespace DAO
