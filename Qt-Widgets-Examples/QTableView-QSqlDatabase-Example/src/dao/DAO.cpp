#include "DAO.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

DAO* DAO::self = 0;

static QSqlDatabase databaseConnection;

DAO::DAO()
{
    if (QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        databaseConnection = QSqlDatabase::database();
    } else {
        databaseConnection = QSqlDatabase::addDatabase("QPSQL", QSqlDatabase::defaultConnection);
        databaseConnection.setDatabaseName("test_db");
        databaseConnection.setPort(5432);
        databaseConnection.setUserName("postgres");
        databaseConnection.setHostName("localhost");
        databaseConnection.setPassword("tyulenev");
    }
}

auto DAO::getConnection() -> DAO*
{
    if (!self) {
        self = new DAO();
    }

    return self;
}

auto DAO::reconnection(const QString hostName, const int port, const QString dataBaseName, const QString userName, const QString password) -> bool
{
    databaseConnection.removeDatabase(QSqlDatabase::defaultConnection);

    //if (!db.isDriverAvailable("QPSQL"))

    databaseConnection = QSqlDatabase::addDatabase("QPSQL", QSqlDatabase::defaultConnection);
    databaseConnection.setDatabaseName(dataBaseName);
    databaseConnection.setPort(port);
    databaseConnection.setUserName(userName);
    databaseConnection.setHostName(hostName);
    databaseConnection.setPassword(password);

    bool result = self->openDB();

    self->closeDB();

    return result;
}

auto DAO::openDB() noexcept -> bool
{
    return databaseConnection.open();
}

auto DAO::closeDB() noexcept -> void
{
    if (databaseConnection.isOpen())
        databaseConnection.close();
}

auto DAO::selectCustomers(QList<Entities::Customer>& customers) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        bool result = query.exec("SELECT * FROM Customers ORDER BY id ASC;");

        if (result) {
            QSqlRecord record = query.record();
            const int idIndex        = record.indexOf("id");
            const int firstNameIndex = record.indexOf("first_name");
            const int lastNameIndex  = record.indexOf("last_name");
            const int eMailIndex     = record.indexOf("e_mail");
            const int ageIndex       = record.indexOf("age");

            while (query.next()) {
                Entities::Customer customer;

                customer.setId(query.value(idIndex).toInt());
                customer.setFirstName(query.value(firstNameIndex).toString());
                customer.setLastName(query.value(lastNameIndex).toString());
                customer.setEmail(query.value(eMailIndex).toString());
                customer.setAge(query.value(ageIndex ).toInt());

                customers << std::move(customer);
            }

            self->closeDB();
        } else {
            self->closeDB();
            //query.lastError() query.lastQuery()
        }
    } else {
        // db error
    }
}

auto DAO::selectProducts(QList<Entities::Product>& products) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        bool result = query.exec("SELECT * FROM Products ORDER BY id ASC;");

        if (result) {
            QSqlRecord record = query.record();
            const int idIndex           = record.indexOf("id");
            const int typeIndex         = record.indexOf("product_type");
            const int nameIndex         = record.indexOf("product_name");
            const int manufacturerIndex = record.indexOf("manufacturer");
            const int countIndex        = record.indexOf("product_count");
            const int priceIndex        = record.indexOf("price");

            while (query.next()) {
                Entities::Product product;

                product.setId(query.value(idIndex).toInt());
                product.setType(query.value(typeIndex).toString());
                product.setName(query.value(nameIndex).toString());
                product.setManufacturer(query.value(manufacturerIndex).toString());
                product.setCount(query.value(countIndex).toInt());
                product.setPrice(query.value(priceIndex).toInt());

                products << std::move(product);
            }

            self->closeDB();
        } else {
            self->closeDB();
            //query.lastError() query.lastQuery()
        }
    } else {
        // db error
    }
}

auto DAO::selectOrders(QList<Entities::Order>& orders) const  -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        bool result = query.exec("SELECT * FROM Orders "
                                 "JOIN Products as Products ON Products.id = Orders.product_id "
                                 "JOIN Customers as Customers ON Customers.id = Orders.customer_id "
                                 "ORDER BY Orders.id ASC;");

        if (result) {
            QSqlRecord record = query.record();

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

            while (query.next()) {
                Entities::Order order;

                order.setId(query.value(orderIdIndex).toInt());
                order.setQuantity(query.value(orderQuantityIndex).toInt());
                order.setDate(query.value(orderDateIndex).toString());
                order.setTime(query.value(orderTimeIndex).toString());

                Entities::Product product;

                product.setId(query.value(productIdIndex).toInt());
                product.setType(query.value(productTypeIndex).toString());
                product.setName(query.value(productNameIndex).toString());
                product.setManufacturer(query.value(productManufacturerIndex).toString());
                product.setCount(query.value(productCountIndex).toInt());
                product.setPrice(query.value(productPriceIndex).toInt());

                order.setProduct(std::move(product));

                Entities::Customer customer;

                customer.setId(query.value(customerIdIndex).toInt());
                customer.setFirstName(query.value(customerFirstNameIndex).toString());
                customer.setLastName(query.value(customerLastNameIndex).toString());
                customer.setEmail(query.value(customerEMailIndex).toString());
                customer.setAge(query.value(customerAgeIndex).toInt());

                order.setCustomer(std::move(customer));

                orders << std::move(order);
            }

            self->closeDB();
        } else {
            self->closeDB();
            //query.lastError() query.lastQuery()
        }
    } else {
        // db error
    }
}

auto DAO::insertCustomer(const Entities::Customer& customer) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        query.prepare("INSERT INTO Customers VALUES (default, :first_name, :last_name, :e_mail, :age);");

        query.bindValue(":first_name", customer.getFirstName());
        query.bindValue(":last_name",  customer.getLastName());
        query.bindValue(":e_mail",     customer.getEmail());
        query.bindValue(":age",        customer.getAge());

        bool result = query.exec();

        if (result) {
            //query.lastError() query.lastQuery()
        }

        self->closeDB();
    } else {
        // db error
    }
}

auto DAO::insertProduct(const Entities::Product& product) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        query.prepare("INSERT INTO Products VALUES (default, :product_type, :product_name, :manufacturer, :product_count, :price);");

        query.bindValue(":product_type",  product.getType());
        query.bindValue(":product_name",  product.getName());
        query.bindValue(":manufacturer",  product.getManufacturer());
        query.bindValue(":product_count", product.getCount());
        query.bindValue(":price",         product.getPrice());

        bool result = query.exec();

        if (result) {
            // qDebug() << query.lastError() query.lastQuery()
        }

        self->closeDB();
    } else {
        // db error
    }
}

auto DAO::deleteCustomer(const int id) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        query.prepare("DELETE FROM Customers WHERE id = :id");
        query.bindValue(":id", id);

        bool result = query.exec();

        if (result) {
            // qDebug() << query.lastError() query.lastQuery()
        }

        self->closeDB();
    } else {
        // db error
    }
}

auto DAO::deleteProduct(const int id) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;
        query.prepare("DELETE FROM Products WHERE id = :id");
        query.bindValue(":id", id);

        bool result = query.exec();

        if (result) {
            // qDebug() << query.lastError() query.lastQuery()
        }

        self->closeDB();
    } else {
        // db error
    }
}

auto DAO::updateCustomer(const Entities::Customer& customer) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        query.prepare("UPDATE Customers SET first_name = :first_name, last_name = :last_name, "
                      "e_mail = :e_mail, age = :age WHERE id = :id;");

        query.bindValue(":first_name", customer.getFirstName());
        query.bindValue(":last_name",  customer.getLastName());
        query.bindValue(":e_mail",     customer.getEmail());
        query.bindValue(":age",        customer.getAge());
        query.bindValue(":id",         customer.getId());

        bool result = query.exec();

        if (result) {
            // qDebug() << query.lastError() query.lastQuery()
        }

        self->closeDB();
    } else {
        // db error
    }
}

auto DAO::updateProduct(const Entities::Product& product) const -> void
{
    if (self->openDB()) {
        QSqlQuery query;

        query.prepare("UPDATE Products SET product_type = :product_type, product_name = :product_name, "
                      "manufacturer = :manufacturer, product_count = :product_count, price = :price WHERE id = :id;");

        query.bindValue(":product_type",  product.getType());
        query.bindValue(":product_name",  product.getName());
        query.bindValue(":manufacturer",  product.getManufacturer());
        query.bindValue(":product_count", product.getCount());
        query.bindValue(":price",         product.getPrice());
        query.bindValue(":id",            product.getId());

        bool result = query.exec();

        if (result) {
            // qDebug() << query.lastError() query.lastQuery()
        }

        self->closeDB();
    } else {
        // db error
    }
}
