#pragma once

#include "Customer.h"
#include <pqxx/pqxx>

class CustomerDAO
{
public:
    CustomerDAO();
    ~CustomerDAO();

    auto selectCustomers(QList<Entities::Customer>& customers) -> void;

    /*!
     * \brief insertCustomers method
     * \code
     * Entities::Customer customer; // id ~ 4
     * customer.setFirstName("Ron");
     * customer.setLastName("Trump");
     * customer.setEmail("ron_t_22@gmail.com");
     * customer.setAge(22);
     * customerDAO->insertCustomers(customer);
     * \endcode
     * \param new customer
     */
    auto insertCustomer(const Entities::Customer& customer) -> void;

private:
    pqxx::connection* connection;

};

