#include "DAO.h"

#include <QDebug>

#include "ConnectionPool.h"

auto DAO::selectCustomers(QList<Entities::Customer>& customers) -> void
{
    std::shared_ptr<soci::session> session = ConnectionPool::getPool()->getConnection();

    try {
        soci::rowset<Entities::Customer> rs = (session->prepare << "SELECT * FROM Customers ORDER BY id ASC;");
        for (auto iterator = rs.begin(); iterator != rs.end(); iterator++) {
            customers.append(*iterator);
        }
    } catch (const soci::soci_error& error) {
        qDebug() << error.what();
    } catch (const std::runtime_error& error) {
        qDebug() << error.what();
    } catch (...) {
        qDebug() << "Unexpected unknown exception occurred.";
    }

    ConnectionPool::getPool()->freeConnection(session);
}

auto DAO::selectProducts(QList<Entities::Product>& products) -> void
{
    std::shared_ptr<soci::session> session = ConnectionPool::getPool()->getConnection();

    try {
        soci::rowset<Entities::Product> pr = (session->prepare << "SELECT * FROM Products ORDER BY id ASC;");
        for (auto iterator = pr.begin(); iterator != pr.end(); iterator++) {
            products.append(*iterator);
        }
    } catch (const soci::soci_error& error) {
        qDebug() << error.what();
    } catch (const std::runtime_error& error) {
        qDebug() <<  error.what();
    } catch (...) {
        qDebug() << "Unexpected unknown exception occurred.";
    }

    ConnectionPool::getPool()->freeConnection(session);
}

auto DAO::selectOrders(QList<Entities::Order>& orders) -> void
{
    std::shared_ptr<soci::session> session = ConnectionPool::getPool()->getConnection();

    try {
        soci::rowset<Entities::Order> pr = (session->prepare << "SELECT * FROM Orders "
                                                                "JOIN Products as Products ON Products.id = Orders.product_id "
                                                                "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                                                                "ORDER BY Orders.id ASC;");
        for (auto iterator = pr.begin(); iterator != pr.end(); iterator++) {
            orders.append(*iterator);
        }
    } catch (const soci::soci_error& error) {
        qDebug() << error.what();
    } catch (const std::runtime_error& error) {
        qDebug() <<  error.what();
    } catch (...) {
        qDebug() << "Unexpected unknown exception occurred.";
    }

    ConnectionPool::getPool()->freeConnection(session);
}
