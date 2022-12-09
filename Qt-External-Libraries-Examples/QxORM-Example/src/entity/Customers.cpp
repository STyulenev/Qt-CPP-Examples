#include "Customers.h"

QX_REGISTER_CPP_QXORM_EXAMPLE(Customer);

namespace qx {

template <> void register_class(QxClass<Customer>& t)
{
    t.setName("public.Customers");
    t.id(&Customer::id, "id");
    t.data(&Customer::firstName, "first_name");
    t.data(&Customer::lastName, "last_name");
    t.data(&Customer::email, "e_mail");
    t.data(&Customer::age, "age");
}

}

