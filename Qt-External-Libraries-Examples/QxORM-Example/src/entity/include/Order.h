#pragma once

#include "Precompiled.h"

class Customer;
class Product;

class QXORM_EXAMPLE_DLL_EXPORT Order
{
public:
    typedef std::shared_ptr<Customer> Customer_ptr;
    typedef std::shared_ptr<Product>  Product_ptr;

    int     id;
    Customer_ptr customer_id;
    Product_ptr  product_id;
    int quantity;
    QDate order_data;
    QTime order_time;

    // -- contructor, virtual destructor
    Order() : id(0) { ; }
    virtual ~Order() { ; }

};

QX_REGISTER_PRIMARY_KEY(Order, int)
QX_REGISTER_HPP_QXORM_EXAMPLE(Order, qx::trait::no_base_class_defined, 0)

typedef std::shared_ptr<Order> Order_ptr;
typedef QVector<Order_ptr>     ListOrder;

