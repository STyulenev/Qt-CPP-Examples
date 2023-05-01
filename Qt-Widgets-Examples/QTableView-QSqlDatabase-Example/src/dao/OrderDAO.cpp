#include "OrderDAO.h"

#include <QMutexLocker>
#include <QDebug>

namespace DAO {

OrderDAO::OrderDAO()
{
    connection = ConnectionPool::getPool()->getConnection();
    query = std::make_shared<QSqlQuery>(*connection.get());
}

OrderDAO::~OrderDAO()
{
    ConnectionPool::getPool()->freeConnection(connection);
}

auto OrderDAO::selectOrders(QList<Entities::Order>& orders) -> void
{
    QMutexLocker locker(&mutex);

    if (connection->open()) {
        bool result = query->exec("SELECT * FROM Orders "
                                  "JOIN Products as Products ON Products.id = Orders.product_id "
                                  "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                                  "ORDER BY Orders.id ASC;");

        if (result) {
            QSqlRecord record = query->record();

            const int orderIdIndex       = record.indexOf("id");
            const int orderQuantityIndex = record.indexOf("quantity");
            const int orderDateIndex     = record.indexOf("order_date");
            const int orderTimeIndex     = record.indexOf("order_time");

            const int customerIdIndex        = record.indexOf("id");
            const int customerFirstNameIndex = record.indexOf("first_name");
            const int customerLastNameIndex  = record.indexOf("last_name");
            const int customerEMailIndex     = record.indexOf("e_mail");
            const int customerAgeIndex       = record.indexOf("age");

            const int productIdIndex           = record.indexOf("id");
            const int productTypeIndex         = record.indexOf("product_type");
            const int productNameIndex         = record.indexOf("product_name");
            const int productManufacturerIndex = record.indexOf("manufacturer");
            const int productCountIndex        = record.indexOf("product_count");
            const int productPriceIndex        = record.indexOf("price");

            while (query->next()) {
                Entities::Order order;

                order.setId(query->value(orderIdIndex).toInt());
                order.setQuantity(query->value(orderQuantityIndex).toInt());
                order.setDate(query->value(orderDateIndex).toString());
                order.setTime(query->value(orderTimeIndex).toString());

                Entities::Product product;

                product.setId(query->value(productIdIndex).toInt());
                product.setType(query->value(productTypeIndex).toString());
                product.setName(query->value(productNameIndex).toString());
                product.setManufacturer(query->value(productManufacturerIndex).toString());
                product.setCount(query->value(productCountIndex).toInt());
                product.setPrice(query->value(productPriceIndex).toInt());

                order.setProduct(std::move(product));

                Entities::Customer customer;

                customer.setId(query->value(customerIdIndex).toInt());
                customer.setFirstName(query->value(customerFirstNameIndex).toString());
                customer.setLastName(query->value(customerLastNameIndex).toString());
                customer.setEmail(query->value(customerEMailIndex).toString());
                customer.setAge(query->value(customerAgeIndex).toInt());

                order.setCustomer(std::move(customer));

                orders << std::move(order);
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

} // namespace DAO
