#include "DAO.h"

#include <QDebug>
#include <iostream>

auto DAO::selectCustomers(QList<Entities::Customer>& customers) -> void
{
    try {
        soci::session sql(soci::postgresql, "dbname=test_db user=postgres password=tyulenev port=5432 host=localhost"); //

        //qDebug() << "Successfully connected to \", " << "using \"" << sql.get_backend_name() << "\" backend.\n";

        soci::rowset<Entities::Customer> rs = (sql.prepare << "SELECT * FROM Customers ORDER BY id ASC;");
        for (auto iterator = rs.begin(); iterator != rs.end(); iterator++) {
            //Entities::Customer& i = *it;
            //i.print();
            customers.append(*iterator);
        }

    } catch (const soci::soci_error& e) {
        std::cout << e.what() << std::endl;
        qDebug() << e.what();
    } catch (const std::runtime_error& e) {
        qDebug() <<  e.what();
    } catch (...) {
        qDebug() << "Unexpected unknown exception occurred.\n";
    }
}

auto DAO::selectProducts(QList<Entities::Product>& products) -> void
{
    try {
        soci::session sql(soci::postgresql, "dbname=test_db user=postgres password=tyulenev port=5432 host=localhost"); //

        //qDebug() << "Successfully connected to \", " << "using \"" << sql.get_backend_name() << "\" backend.\n";

        soci::rowset<Entities::Product> pr = (sql.prepare << "SELECT * FROM Products ORDER BY id ASC;");
        for (auto iterator = pr.begin(); iterator != pr.end(); iterator++) {
            //Entities::Product& i = *iterator;
            //i.print();
            products.append(*iterator);
        }

    } catch (const soci::soci_error& e) {
        std::cout << e.what() << std::endl;
        qDebug() << e.what();
    } catch (const std::runtime_error& e) {
        qDebug() <<  e.what();
    } catch (...) {
        qDebug() << "Unexpected unknown exception occurred.\n";
    }
}

auto DAO::selectOrders(QList<Entities::Order>& orders) -> void
{
    try {
        soci::session sql(soci::postgresql, "dbname=test_db user=postgres password=tyulenev port=5432 host=localhost"); //

        //qDebug() << "Successfully connected to \", " << "using \"" << sql.get_backend_name() << "\" backend.\n";

        soci::rowset<Entities::Order> pr = (sql.prepare << "SELECT * FROM Orders "
                                                           "JOIN Products as Products ON Products.id = Orders.product_id "
                                                           "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                                                           "ORDER BY Orders.id ASC;");
        for (auto iterator = pr.begin(); iterator != pr.end(); iterator++) {
            //Entities::Order& i = *iterator;
            //i.print();
            orders.append(*iterator);
        }

    } catch (const soci::soci_error& e) {
        std::cout << e.what() << std::endl;
        qDebug() << e.what();
    } catch (const std::runtime_error& e) {
        qDebug() <<  e.what();
    } catch (...) {
        qDebug() << "Unexpected unknown exception occurred.\n";
    }
}
