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

void DAO::print()
{
    /*qx_query query;
    query.orderAsc("id");
    QSqlError daoError = qx::dao::fetch_by_query_with_all_relation(query, roles);*/

    /*ListCustomer roles;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", roles);

    qDebug() << "length = " << roles.length();

    for (auto&& el : roles) {
        qDebug() << el->id << el->firstName << el->lastName << el->email << el->age;
    }*/


    ListOrder orders;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", orders);

    for (auto&& el : orders) {
        qDebug() << el->id << el->customer_id->firstName << el->product_id->product_name;
    }
}

