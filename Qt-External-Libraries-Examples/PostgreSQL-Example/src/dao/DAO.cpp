#include "DAO.h"

#include "Connection.h"

DAO::DAO()
{

}

auto DAO::getCustomersList() -> QList<Entities::Customer>
{
    QList<Entities::Customer> customers;

    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        qDebug() << "isOpen()";

        auto result = connection->runRequest("SELECT * FROM Customers");

        int res_id = PQfnumber(result, "id");
        int res_first_name = PQfnumber(result, "first_name");
        int res_last_name = PQfnumber(result, "last_name");
        int res_e_mail  = PQfnumber(result, "e_mail");
        int res_age  = PQfnumber(result, "age");

        for (int i = 0; i < PQntuples(result); i++) {
            Entities::Customer customer;

            customer.setId(atoi(PQgetvalue(result, i, res_id)));
            customer.setFirstName(PQgetvalue(result, i, res_first_name));
            customer.setLastName(PQgetvalue(result, i, res_last_name));
            customer.setEmail(PQgetvalue(result, i, res_e_mail));
            customer.setAge(atoi(PQgetvalue(result, i, res_age)));

            customers << std::move(customer);
        }

        PQclear(result);
    } else {
        qDebug() << "close()";
    }

    return customers;
}

auto DAO::getProductsList() -> QList<Entities::Product>
{
    QList<Entities::Product> products;

    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        qDebug() << "isOpen()";

        auto result = connection->runRequest("SELECT * FROM Products");

        int res_id = PQfnumber(result, "id");
        int res_product_type = PQfnumber(result, "product_type");
        int res_product_name = PQfnumber(result, "product_name");
        int res_manufacturer  = PQfnumber(result, "manufacturer");
        int res_product_count  = PQfnumber(result, "product_count");
        int res_price  = PQfnumber(result, "price");

        for (int i = 0; i < PQntuples(result); i++) {
            Entities::Product product;

            product.setId(atoi(PQgetvalue(result, i, res_id)));
            product.setProduct_type(PQgetvalue(result, i, res_product_type));
            product.setProduct_name(PQgetvalue(result, i, res_product_name));
            product.setManufacturer(PQgetvalue(result, i, res_manufacturer));
            product.setProduct_count(atoi(PQgetvalue(result, i, res_product_count)));
            product.setPrice(atoi(PQgetvalue(result, i, res_price)));

            products << std::move(product);
        }

        PQclear(result);
    } else {
        qDebug() << "close()";
    }

    return products;;
}
