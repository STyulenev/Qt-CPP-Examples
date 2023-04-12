#include "DAO.h"
#include "Connection.h"

auto DAO::selectCustomers(QList<Entities::Customer>& customers) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest("SELECT * FROM Customers ORDER BY id ASC;");

        if (PQresultStatus(result) != ExecStatusType::PGRES_TUPLES_OK) {
            qDebug() << "Select customers: " << connection->getLastError(); // or throw ...
        } else {
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
        }

        PQclear(result);
    } else {
        qDebug() << "Select customers: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::selectProducts(QList<Entities::Product>& products) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest("SELECT * FROM Products ORDER BY id ASC;");

        if (PQresultStatus(result) != ExecStatusType::PGRES_TUPLES_OK) {
            qDebug() << "Select products: " << connection->getLastError(); // or throw ...
        } else {
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
        }

        PQclear(result);
    } else {
        qDebug() << "Select products: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::selectOrders(QList<Entities::Order>& orders) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {

        auto result = connection->runRequest("SELECT * FROM Orders "
                                             "JOIN Products as Products ON Products.id = Orders.product_id "
                                             "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                                             "ORDER BY Orders.id ASC;");

        if (PQresultStatus(result) != ExecStatusType::PGRES_TUPLES_OK) {
            qDebug() << "Select orders: " << connection->getLastError(); // or throw ...
        } else {
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
        }

        PQclear(result);
    } else {
        qDebug() << "Select orders: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::insertCustomer(const Entities::Customer& customer) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest(QString("INSERT INTO Customers VALUES (default, '%1', '%2', '%3', %4);")
                                             .arg(customer.getFirstName())
                                             .arg(customer.getLastName())
                                             .arg(customer.getEmail())
                                             .arg(customer.getAge()));

        if (PQresultStatus(result) != ExecStatusType::PGRES_COMMAND_OK) {
            qDebug() << "Insert customer: " << connection->getLastError(); // or throw ...
        }

        PQclear(result);
    } else {
        qDebug() << "Insert customer: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::insertProduct(const Entities::Product& product) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest(QString("INSERT INTO Products VALUES (default, '%1', '%2', '%3', %4, %5);")
                                             .arg(product.getType())
                                             .arg(product.getName())
                                             .arg(product.getManufacturer())
                                             .arg(product.getCount())
                                             .arg(product.getPrice()));

        if (PQresultStatus(result) != ExecStatusType::PGRES_COMMAND_OK) {
            qDebug() << "Insert product: " << connection->getLastError(); // or throw ...
        }

        PQclear(result);
    } else {
        qDebug() << "Insert product: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::deleteCustomer(const int id) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest(QString("DELETE FROM Customers WHERE id = %1;").arg(id));
        if (PQresultStatus(result) != ExecStatusType::PGRES_COMMAND_OK) {
            qDebug() << "Delete customer: " << connection->getLastError(); // or throw ...
        }

        PQclear(result);
    } else {
        qDebug() << "Delete customer: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::deleteProduct(const int id) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest(QString("DELETE FROM Products WHERE id = %1;").arg(id));

        if (PQresultStatus(result) != ExecStatusType::PGRES_COMMAND_OK) {
            qDebug() << "Delete product: " << connection->getLastError(); // or throw ...
        }

        PQclear(result);
    } else {
        qDebug() << "Delete product: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::updateCustomer(const Entities::Customer& customer) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest(QString("UPDATE Customers SET first_name = '%1', last_name = '%2', e_mail = '%3', age = %4 WHERE id = %5;")
                                             .arg(customer.getFirstName())
                                             .arg(customer.getLastName())
                                             .arg(customer.getEmail())
                                             .arg(customer.getAge())
                                             .arg(customer.getId()));

        if (PQresultStatus(result) != ExecStatusType::PGRES_COMMAND_OK) {
            qDebug() << "Update customer: " << connection->getLastError(); // or throw ...
        }

        PQclear(result);
    } else {
        qDebug() << "Update customer: " << connection->getLastError(); // or throw ...
    }
}

auto DAO::updateProduct(const Entities::Product& product) -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        auto result = connection->runRequest(QString("UPDATE Products SET product_type = '%1', product_name = '%2', "
                                                     "manufacturer = '%3', product_count = %4, price = %5 WHERE id = %6;")
                                             .arg(product.getType())
                                             .arg(product.getName())
                                             .arg(product.getManufacturer())
                                             .arg(product.getCount())
                                             .arg(product.getPrice())
                                             .arg(product.getId()));

        if (PQresultStatus(result) != ExecStatusType::PGRES_COMMAND_OK) {
            qDebug() << "Update product: " << connection->getLastError(); // or throw ...
        }

        PQclear(result);
    } else {
        qDebug() << "Update product: " << connection->getLastError(); // or throw ...
    }
}
