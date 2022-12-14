#include "Order.h"
#include "Customer.h"
#include "Product.h"

QX_REGISTER_CPP_QXORM_EXAMPLE(Order);

namespace qx {

template <> void register_class(QxClass<Order>& order)
{
    order.setName("public.Orders");

    order.id(&Order::id, "id");

    order.data(&Order::quantity, "quantity");
    order.data(&Order::order_data, "order_data");
    order.data(&Order::order_time, "order_time");

    order.relationManyToOne(&Order::customer_id, "customer_id");
    order.relationManyToOne(&Order::product_id, "product_id");
}

}

