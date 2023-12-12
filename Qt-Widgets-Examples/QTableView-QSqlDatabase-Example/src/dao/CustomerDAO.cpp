#include "CustomerDAO.h"

#include <QMutexLocker>
#include <QDebug>

namespace DAO {

CustomerDAO::CustomerDAO(QObject* parent) :
    QObject(parent)
{
    connection = ConnectionPool::getPool()->getConnection();
    query = std::make_shared<QSqlQuery>(*connection.get());
}

CustomerDAO::~CustomerDAO()
{
    ConnectionPool::getPool()->freeConnection(connection);
}

auto CustomerDAO::selectCustomers(QList<Entities::Customer>& customers) -> void
{
    QMutexLocker locker(&mutex);

    if (connection->open()) {
        bool result = query->exec("SELECT * FROM Customers ORDER BY id ASC;");

        if (result) {
            QSqlRecord record = query->record();
            const int idIndex        = record.indexOf("id");
            const int firstNameIndex = record.indexOf("first_name");
            const int lastNameIndex  = record.indexOf("last_name");
            const int eMailIndex     = record.indexOf("e_mail");
            const int ageIndex       = record.indexOf("age");

            while (query->next()) {
                Entities::Customer customer;

                customer.setId(query->value(idIndex).toInt());
                customer.setFirstName(query->value(firstNameIndex).toString());
                customer.setLastName(query->value(lastNameIndex).toString());
                customer.setEmail(query->value(eMailIndex).toString());
                customer.setAge(query->value(ageIndex ).toInt());

                customers << std::move(customer);
            }

            connection->close();
        } else {
            connection->close();
            qDebug() << "Error:" << query->lastError().text();
        }

        query->clear();
    } else {
        qDebug() << "Error. Database not open.";
    }
}

auto CustomerDAO::insertCustomer(const Entities::Customer& customer) -> void
{
    QMutexLocker locker(&mutex);

    if (connection->open()) {
        query->prepare("INSERT INTO Customers VALUES (default, :first_name, :last_name, :e_mail, :age);");

        query->bindValue(":first_name", customer.getFirstName());
        query->bindValue(":last_name",  customer.getLastName());
        query->bindValue(":e_mail",     customer.getEmail());
        query->bindValue(":age",        customer.getAge());

        bool result = query->exec();

        if (result) {
            qDebug() << "Error:" << query->lastError().text();
        }

        query->clear();
        connection->close();
    } else {
        qDebug() << "Error. Database not open.";
    }
}

auto CustomerDAO::deleteCustomer(const int id) -> void
{
    QMutexLocker locker(&mutex);

    if (connection->open()) {
        query->prepare("DELETE FROM Customers WHERE id = :id");
        query->bindValue(":id", id);

        bool result = query->exec();

        if (result) {
            qDebug() << "Error:" << query->lastError().text();
        }

        query->clear();
        connection->close();
    } else {
        qDebug() << "Error. Database not open.";
    }
}

auto CustomerDAO::updateCustomer(const Entities::Customer& customer) -> void
{
    QMutexLocker locker(&mutex);

    if (connection->open()) {
        query->prepare("UPDATE Customers SET first_name = :first_name, last_name = :last_name, "
                       "e_mail = :e_mail, age = :age WHERE id = :id;");

        query->bindValue(":first_name", customer.getFirstName());
        query->bindValue(":last_name",  customer.getLastName());
        query->bindValue(":e_mail",     customer.getEmail());
        query->bindValue(":age",        customer.getAge());
        query->bindValue(":id",         customer.getId());

        bool result = query->exec();

        if (result) {
            qDebug() << "Error:" << query->lastError().text();
        }

        query->clear();
        connection->close();
    } else {
        qDebug() << "Error. Database not open.";
    }
}

} // namespace DAO
