#pragma once

#include <QDebug>
#include <QMutex>

#include "Customer.h"
#include "ConnectionPool.h"

namespace DAO {

class CustomerDAO
{
private:
    std::shared_ptr<Connection> connection;
    QMutex mutex;

public:
    CustomerDAO();
    ~CustomerDAO();

    auto selectCustomers(QList<Entities::Customer>& customers) -> void;

};

} // namespace DAO
