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

        /**/

    } catch (std::exception const& error) {
        qDebug() << "ERROR: " << error.what() << '\n';
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
            //qDebug() << id << first_name;
            Entities::Customer customer;

            customer.setId(id);
            customer.setFirstName(first_name.c_str());
            customer.setLastName(last_name.c_str());
            customer.setEmail(e_mail.c_str());
            customer.setAge(age);

            customers << std::move(customer);
        }
    } catch (std::exception const& error) {
        qDebug() << "ERROR: " << error.what() << '\n';
    }
}
