#include "CustomerDAO.h"

#include <QMutexLocker>
#include <QDebug>

namespace DAO {

CustomerDAO::CustomerDAO()
{
    connection = ConnectionPool::getPool()->getConnection();
}

CustomerDAO::~CustomerDAO()
{
    ConnectionPool::getPool()->freeConnection(connection);
}

auto CustomerDAO::selectCustomers(QList<Entities::Customer>& customers) -> void
{
    QMutexLocker locker(&mutex);

    if (connection->open()) {
        if (!connection->query("SELECT id, first_name, last_name, e_mail, age FROM Customers ORDER BY id ASC;")) {
            //qDebug() << connection->getLastError();
        }

        MYSQL_RES* res;
        MYSQL_ROW row;

        res = mysql_use_result(connection->getConnection().get());

        while ((row = mysql_fetch_row(res))) {
            Entities::Customer customer;

            customer.setId(QString::fromLocal8Bit(row[0]).toInt());
            customer.setFirstName(QString(row[1]));
            customer.setLastName(QString(row[2]));
            customer.setEmail(QString(row[3]));
            customer.setAge(QString::fromLocal8Bit(row[4]).toInt());

            customers << std::move(customer);
        }

        mysql_free_result(res);

        //connection->close();
    }
}

} // namespace DAO
