#pragma once

#include "Precompiled.h"

class QXORM_EXAMPLE_DLL_EXPORT Product
{
public:
    int     id;
    QString product_type;
    QString product_name;
    QString manufacturer;
    int     product_count;
    long    price;

    // -- contructor, virtual destructor
    Product() : id(0) { ; }
    virtual ~Product() { ; }

};

QX_REGISTER_PRIMARY_KEY(Product, int)
QX_REGISTER_HPP_QXORM_EXAMPLE(Product, qx::trait::no_base_class_defined, 0)

typedef std::shared_ptr<Product> Product_ptr;
typedef QVector<Product_ptr>     ListProduct;

