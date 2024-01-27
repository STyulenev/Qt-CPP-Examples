#include "CustomerDAO.h"

#include <QDebug>

CustomerDAO::CustomerDAO()
{
    try {
        connection = new pqxx::connection {
            "host='localhost' "
            "port='5432' "
            "dbname='test_db' "
            "user='postgres' "
            "password='tyulenev' "
        };

        qDebug() << "Connected to" << connection->dbname();
    } catch (std::exception const& error) {
        qDebug() << "error: " << error.what();
    }
}

CustomerDAO::~CustomerDAO()
{
    delete connection;
}

void CustomerDAO::selectCustomers(QList<Entities::Customer>& customers)
{
    try {
        pqxx::work tx (*connection);

        for (auto [id, first_name, last_name, e_mail, age] : tx.query<int, std::string, std::string, std::string, int>("SELECT * FROM Customers ORDER BY id ASC;")) {
            Entities::Customer customer;

            customer.setId(id);
            customer.setFirstName(first_name.c_str());
            customer.setLastName(last_name.c_str());
            customer.setEmail(e_mail.c_str());
            customer.setAge(age);

            customers << std::move(customer);
        }
    } catch (std::exception const& error) {
        qDebug() << "error: " << error.what();
    }
}

void CustomerDAO::insertCustomer(const Entities::Customer& customer)
{
    pqxx::work tx (*connection);

    const QString query = QString("INSERT INTO Customers VALUES (default, '%1', '%2', '%3', %4);")
                              .arg(customer.getFirstName())
                              .arg(customer.getLastName())
                              .arg(customer.getEmail())
                              .arg(customer.getAge());

    tx.exec(query.toStdString());
    tx.commit();
}

void CustomerDAO::updateCustomer(const Entities::Customer &customer)
{
    pqxx::work tx (*connection);

    const QString query = QString("UPDATE Customers SET first_name = '%1', last_name = '%2', e_mail = '%3', age = %4 WHERE id = %5;")
                              .arg(customer.getFirstName())
                              .arg(customer.getLastName())
                              .arg(customer.getEmail())
                              .arg(customer.getAge())
                              .arg(customer.getId());

    tx.exec(query.toStdString());
    tx.commit();
}
