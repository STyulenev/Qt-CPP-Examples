#pragma once

#include "Customer.h"

class DAO
{
public:
    DAO();

    static auto getCustomersList() -> QList<Entities::Customer>;
};

