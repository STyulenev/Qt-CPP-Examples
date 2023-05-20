#include "OrderDAO.h"

#include <QMutexLocker>
#include <QDebug>

namespace DAO {

OrderDAO::OrderDAO()
{
    connection = ConnectionPool::getPool()->getConnection();
}

OrderDAO::~OrderDAO()
{
    ConnectionPool::getPool()->freeConnection(connection);
}

auto OrderDAO::selectOrders(QList<Entities::Order>& orders) -> void
{
    QMutexLocker locker(&mutex);

    if (!connection->query("SELECT Orders.id, Orders.quantity, Orders.order_date, Orders.order_time, "
                           "Customers.id, Customers.first_name, Customers.last_name, Customers.e_mail, Customers.age, "
                           "Products.id, Products.product_type, Products.product_name, Products.manufacturer, Products.product_count, Products.price "
                           "FROM Orders "
                           "JOIN Products as Products ON Products.id = Orders.product_id "
                           "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                           "ORDER BY Orders.id ASC;")) {
        qDebug() << connection->getLastError();
    }

    MYSQL_RES* res;
    MYSQL_ROW row;

    res = mysql_use_result(connection->getConnection().get());

    while ((row = mysql_fetch_row(res))) {
        Entities::Order order;

        order.setId(QString::fromLocal8Bit(row[1]).toInt());
        order.setQuantity(QString::fromLocal8Bit(row[2]).toInt());
        order.setDate(QString(row[3]));
        order.setTime(QString(row[4]));

        Entities::Product product;

        product.setId(QString::fromLocal8Bit(row[5]).toInt());
        product.setType(QString(row[6]));
        product.setName(QString(row[7]));
        product.setManufacturer(QString(row[8]));
        product.setCount(QString::fromLocal8Bit(row[9]).toInt());
        product.setPrice(QString::fromLocal8Bit(row[10]).toInt());

        order.setProduct(std::move(product));

        Entities::Customer customer;

        customer.setId(QString::fromLocal8Bit(row[11]).toInt());
        customer.setFirstName(QString(row[12]));
        customer.setLastName(QString(row[13]));
        customer.setEmail(QString(row[14]));
        customer.setAge(QString::fromLocal8Bit(row[15]).toInt());

        order.setCustomer(std::move(customer));

        orders << std::move(order);
    }

    mysql_free_result(res);
}

} // namespace DAO
