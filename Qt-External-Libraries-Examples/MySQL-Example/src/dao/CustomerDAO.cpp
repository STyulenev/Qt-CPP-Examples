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
}

auto CustomerDAO::insertCustomer(const Entities::Customer& customer) -> void
{
    QMutexLocker locker(&mutex);

    QString query = QString("INSERT INTO Customers VALUES (default, '%1', '%2', '%3', %4);")
            .arg(customer.getFirstName())
            .arg(customer.getLastName())
            .arg(customer.getEmail())
            .arg(customer.getAge());

    if (!connection->query(query)) {
        //qDebug() << connection->getLastError();
    }
}

auto CustomerDAO::deleteCustomer(const int id) -> void
{
    QMutexLocker locker(&mutex);

    QString query = QString("DELETE FROM Customers WHERE id = %1;").arg(id);

    if (!connection->query(query)) {
        //qDebug() << connection->getLastError();
    }
}

auto CustomerDAO::updateCustomer(const Entities::Customer& customer) -> void
{
    QMutexLocker locker(&mutex);

    QString query = QString("UPDATE Customers SET first_name = '%1', last_name = '%2', "
                            "e_mail = '%3', age = %4 WHERE id = %5;")
            .arg(customer.getFirstName())
            .arg(customer.getLastName())
            .arg(customer.getEmail())
            .arg(customer.getAge())
            .arg(customer.getId());

    if (!connection->query(query)) {
        //qDebug() << connection->getLastError();
    }
}

} // namespace DAO
