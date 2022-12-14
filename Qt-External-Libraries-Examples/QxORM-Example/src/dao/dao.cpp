#include "dao.h"

DAO* DAO::self = 0;

DAO* DAO::getConnection()
{
    if (!self) {
        qx::QxSqlDatabase::getSingleton()->setDriverName("QPSQL");
        qx::QxSqlDatabase::getSingleton()->setDatabaseName("test_db");
        qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
        qx::QxSqlDatabase::getSingleton()->setUserName("postgres");
        qx::QxSqlDatabase::getSingleton()->setPassword("tyulenev");

        self = new DAO();
    }

    return self;
}

auto DAO::getListOfCustomers() -> ListCustomer
{
    ListCustomer roles;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", roles);

    if (daoError.isValid())
        qDebug() << daoError.text();

    /*for (auto&& el : roles) {
        qDebug() << el->id << el->firstName << el->lastName << el->email << el->age;
    }*/

    return roles;
}

auto DAO::getListOfOrders() -> ListOrder
{
    ListOrder orders;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", orders);

    /*for (auto&& el : orders) {
        qDebug() << el->id << el->customer_id->firstName << el->product_id->product_name;
    }*/

    return orders;
}

auto DAO::getListOfProducts() -> ListProduct
{
    ListProduct products;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", products);

    /*for (auto&& el : products) {
        qDebug() << el->id << el->manufacturer << el->product_type << el->product_name << el->product_count << el->price;
    }*/

    return products;
}

