#include "DAO.h"

#include "Connection.h"

DAO::DAO()
{

}

auto DAO::getCustomersList(QList<Entities::Customer>& customers) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest("SELECT * FROM Customers");

        int resId        = PQfnumber(result, "id");
        int resFirstName = PQfnumber(result, "first_name");
        int resLastName  = PQfnumber(result, "last_name");
        int resEmail     = PQfnumber(result, "e_mail");
        int resAge       = PQfnumber(result, "age");

        for (int i = 0; i < PQntuples(result); i++) {
            Entities::Customer customer;

            customer.setId(atoi(PQgetvalue(result, i, resId)));
            customer.setFirstName(PQgetvalue(result, i, resFirstName));
            customer.setLastName(PQgetvalue(result, i, resLastName));
            customer.setEmail(PQgetvalue(result, i, resEmail));
            customer.setAge(atoi(PQgetvalue(result, i, resAge)));

            customers << std::move(customer);
        }

        PQclear(result);
    } else {
        // throw ...
    }
}

auto DAO::getProductsList(QList<Entities::Product>& products) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest("SELECT * FROM Products");

        int resId           = PQfnumber(result, "id");
        int resType         = PQfnumber(result, "product_type");
        int resName         = PQfnumber(result, "product_name");
        int resManufacturer = PQfnumber(result, "manufacturer");
        int resCount        = PQfnumber(result, "product_count");
        int resPrice        = PQfnumber(result, "price");

        for (int i = 0; i < PQntuples(result); i++) {
            Entities::Product product;

            product.setId(atoi(PQgetvalue(result, i, resId)));
            product.setType(PQgetvalue(result, i, resType));
            product.setName(PQgetvalue(result, i, resName));
            product.setManufacturer(PQgetvalue(result, i, resManufacturer));
            product.setCount(atoi(PQgetvalue(result, i, resCount)));
            product.setPrice(atoi(PQgetvalue(result, i, resPrice)));

            products << std::move(product);
        }

        PQclear(result);
    } else {
        // throw ...
    }
}

auto DAO::getOrdersList(QList<Entities::Order>& orders) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {

        auto result = connection->runRequest("SELECT * FROM Orders "
                                             "JOIN Products as Products ON Products.id = Orders.product_id "
                                             "JOIN Customers as Customers ON Customers.id = Orders.customer_id;");

        int resOrderId       = PQfnumber(result, "id");
        int resOrderQuantity = PQfnumber(result, "quantity");
        int resOrderDate     = PQfnumber(result, "order_date");
        int resOrderTime     = PQfnumber(result, "order_time");

        int resProductId           = PQfnumber(result, "product_id");
        int resProductType         = PQfnumber(result, "product_type");
        int resProductName         = PQfnumber(result, "product_name");
        int resProductManufacturer = PQfnumber(result, "manufacturer");
        int resProductCount        = PQfnumber(result, "product_count");
        int resProductPrice        = PQfnumber(result, "price");

        int resCustomerId        = PQfnumber(result, "customer_id");
        int resCustomerFirstName = PQfnumber(result, "first_name");
        int resCustomerLastName  = PQfnumber(result, "last_name");
        int resCustomerEMail     = PQfnumber(result, "e_mail");
        int resCustomerAge       = PQfnumber(result, "age");

        for (int i = 0; i < PQntuples(result); i++) {
            Entities::Order order;

            order.setId(atoi(PQgetvalue(result, i, resOrderId)));
            order.setQuantity(atoi(PQgetvalue(result, i, resOrderQuantity)));
            order.setDate(PQgetvalue(result, i, resOrderDate));
            order.setTime(PQgetvalue(result, i, resOrderTime));

            Entities::Product product;

            product.setId(atoi(PQgetvalue(result, i, resProductId)));
            product.setType(PQgetvalue(result, i, resProductType));
            product.setName(PQgetvalue(result, i, resProductName));
            product.setManufacturer(PQgetvalue(result, i, resProductManufacturer));
            product.setCount(atoi(PQgetvalue(result, i, resProductCount)));
            product.setPrice(atoi(PQgetvalue(result, i, resProductPrice)));

            order.setProduct(std::move(product));

            Entities::Customer customer;

            customer.setId(atoi(PQgetvalue(result, i, resCustomerId)));
            customer.setFirstName(PQgetvalue(result, i, resCustomerFirstName));
            customer.setLastName(PQgetvalue(result, i, resCustomerLastName));
            customer.setEmail(PQgetvalue(result, i, resCustomerEMail));
            customer.setAge(atoi(PQgetvalue(result, i, resCustomerAge)));

            order.setCustomer(std::move(customer));

            orders << std::move(order);
        }

        PQclear(result);
    } else {
        // throw ...
    }
}
