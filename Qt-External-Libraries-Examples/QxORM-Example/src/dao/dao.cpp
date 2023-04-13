#include "DAO.h"

DAO* DAO::self = 0;

auto DAO::getConnection() -> DAO*
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
    ListCustomer customers;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", customers);

    if (daoError.isValid())
        qDebug() << daoError.text();

    return customers;
}

auto DAO::getListOfOrders() -> ListOrder
{
    ListOrder orders;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", orders);

    return orders;
}

auto DAO::getListOfProducts() -> ListProduct
{
    ListProduct products;
    QSqlError daoError = qx::dao::fetch_all_with_relation("*", products);

    return products;
}

auto DAO::getListOfCustomersWithWhere(/* ... */) -> ListCustomer
{
    ListCustomer customers;

    qx_query query;
    query.where("age") // WHERE age > 20 AND first_name LIKE 'M%'
            .isGreaterThan(20) // .isEqualTo(30) or .isLessThan(40) or .isBetween(20, 40)
            .and_("first_name").like("M%");

    QSqlError daoError = qx::dao::fetch_by_query_with_all_relation(query, customers);

    if (daoError.isValid())
        qDebug() << daoError.text(); // throw ...

    return customers;
}

auto DAO::getListOfOrdersWithWhere(/* ... */) -> ListOrder
{
    ListOrder orders;
    qx_query query("WHERE quantity = 1"); // your request

    QSqlError daoError = qx::dao::fetch_by_query_with_all_relation(query, orders);

    return orders;
}

auto DAO::getListOfProductsWithWhere(/* ... */) -> ListProduct
{
    ListProduct products;

    qx_query query;
    query.where("price") // WHERE price > 30000 AND product_type = 'Phone' ORDER BY id DESC LIMIT 10
            .isGreaterThan(30000)
            .and_("product_type").isEqualTo("Phone")
            .orderDesc("id")
            .limit(10);

    QSqlError daoError = qx::dao::fetch_by_query_with_all_relation(query, products);

    return products;
}

auto DAO::insertNewCustomer(/* ... */) -> void
{
    Customer_ptr customer;
    customer.reset(new Customer());

    //customer->id = ...; или будет default
    customer->firstName = "Mark";
    customer->lastName  = "Wo";
    customer->age = 29;
    customer->email = "mark_wo@gmail.com";

    QSqlError daoError = qx::dao::insert(customer);

    if (daoError.isValid())
        qDebug() << daoError.text(); // throw ...
}

auto DAO::insertNewProduct() -> void
{
    qx::QxSqlQuery query("INSERT INTO Products VALUES (default, :product_type, :product_name, :manufacturer, :product_count, :price);");
    query.bind(":product_type", "Phone");
    query.bind(":product_name", "Redmi 10 Lite");
    query.bind(":manufacturer", "Xiaomi");
    query.bind(":product_count", 10);
    query.bind(":price", 15000);

    QSqlError daoError = qx::dao::call_query(query);

    if (daoError.isValid())
        qDebug() << daoError.text(); // throw ...
}

auto DAO::deleteCustomer(/* ... */) -> void
{
    qx::QxSqlQuery query;
    query.where("id").isEqualTo(4);

    QSqlError daoError = qx::dao::delete_by_query<Customer>(query);

    if (daoError.isValid())
        qDebug() << daoError.text(); // throw ...
}
