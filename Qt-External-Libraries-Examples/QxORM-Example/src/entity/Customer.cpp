#include "Customer.h"

QX_REGISTER_CPP_QXORM_EXAMPLE(Customer);

namespace qx {

template <> void register_class(QxClass<Customer>& customer)
{
    customer.setName("public.Customers");

    customer.id(&Customer::id, "id");

    customer.data(&Customer::firstName, "first_name");
    customer.data(&Customer::lastName,  "last_name");
    customer.data(&Customer::email,     "e_mail");
    customer.data(&Customer::age,       "age");
}

}
