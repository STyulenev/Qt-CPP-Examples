#include "Product.h"

QX_REGISTER_CPP_QXORM_EXAMPLE(Product);

namespace qx {

template <> void register_class(QxClass<Product>& product)
{
    product.setName("public.Products");

    product.id(&Product::id, "id");

    product.data(&Product::product_type, "product_type");
    product.data(&Product::product_name, "product_name");
    product.data(&Product::manufacturer, "manufacturer");
    product.data(&Product::product_count, "product_count");
    product.data(&Product::price, "price");
}

}

