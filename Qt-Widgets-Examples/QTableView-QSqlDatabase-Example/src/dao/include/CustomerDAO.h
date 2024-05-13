#pragma once

#include <QMutex>

#include "Customer.h"
#include "ConnectionPool.h"

namespace DAO {

class CustomerDAO : public QObject
{
    Q_OBJECT

private:
    std::shared_ptr<QSqlDatabase> connection;
    std::shared_ptr<QSqlQuery> query;
    QMutex mutex;

public:
    explicit CustomerDAO(QObject* parent = nullptr);
    ~CustomerDAO();

    auto selectCustomers(QList<Entities::Customer>& customers) -> void;
    auto insertCustomer(const Entities::Customer& customer) -> void;
    auto deleteCustomer(const int id) -> void;
    auto updateCustomer(const Entities::Customer& customer) -> void;

};

} // namespace DAO
