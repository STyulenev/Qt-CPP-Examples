#pragma once

#include "Customer.h"
#include "Product.h"

class DAO
{
public:
    DAO();

    static auto getCustomersList() -> QList<Entities::Customer>;

    static auto getProductsList() -> QList<Entities::Product>;
};

