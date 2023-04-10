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
