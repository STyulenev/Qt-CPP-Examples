#include "OrderDAO.h"

#include "ConnectionPool.h"
#include <pqxx/pqxx>
#include <QDebug>

OrderDAO::OrderDAO()
{
    try {
        connection = ConnectionPool::getPool()->getConnection();

        qDebug() << "Connected to" << connection->dbname();
    } catch (const std::exception& error) {
        qDebug() << "error: " << error.what();
    }
}

OrderDAO::~OrderDAO()
{
    ConnectionPool::getPool()->freeConnection(connection);
}

void OrderDAO::selectOrders(QList<Entities::Order>& orders)
{
    try {
        pqxx::work tx (*connection);

        for (auto [id, quantity, order_date, order_time,
                   product_id, product_type, product_name, manufacturer, product_count, price,
                   customer_id, first_name, last_name, e_mail, age] :
             tx.query<int, int, std::string, std::string,
                      int, std::string, std::string, std::string, int, int,
                      int, std::string, std::string, std::string, int>("SELECT Orders.id, quantity, order_date, order_time, "
                                                                            "product_id, product_type, product_name, manufacturer, product_count, price, "
                                                                            "customer_id,first_name, last_name, e_mail, age FROM Orders as Orders "
                                                                            "JOIN Products as Products ON Products.id = Orders.product_id "
                                                                            "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                                                                            "ORDER BY Orders.id ASC;")) {

            Entities::Order order;

            order.setId(id);
            order.setQuantity(quantity);
            order.setDate(order_date.c_str());
            order.setTime(order_time.c_str());

            Entities::Product product;

            product.setId(product_id);
            product.setType(product_type.c_str());
            product.setName(product_name.c_str());
            product.setManufacturer(manufacturer.c_str());
            product.setCount(product_count);
            product.setPrice(price);

            order.setProduct(std::move(product));

            Entities::Customer customer;

            customer.setId(customer_id);
            customer.setFirstName(first_name.c_str());
            customer.setLastName(last_name.c_str());
            customer.setEmail(e_mail.c_str());
            customer.setAge(age);

            order.setCustomer(std::move(customer));

            orders << std::move(order);
        }
    } catch (const std::exception& error) {
        qDebug() << "error: " << error.what();
    }
}
