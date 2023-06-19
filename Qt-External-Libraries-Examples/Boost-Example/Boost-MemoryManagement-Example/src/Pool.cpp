#include "Pool.h"

#include <QDebug>

#include <boost/pool/object_pool.hpp>
#include <boost/pool/singleton_pool.hpp>

auto Pool::ObjectPoolExample() -> void
{
    boost::object_pool<int> pool1;
    boost::object_pool<int> pool2 {64, 0}; // { the size of the memory block, the maximum size of the memory block}

    int* i = pool1.malloc(); // get memory
    *i = 1;
    int* j = pool1.construct(37); // initializes the object

    qDebug() << "j =" << *j << " i = "<< *i;

    pool2.construct();  // It gives the new memory block of twice the size from previous one.

    qDebug() << "new memory block of pool2 = " << pool2.get_next_size();

    pool2.set_next_size(8);

    qDebug() << "After setting the new size of pool2 = " << pool2.get_next_size();

    pool1.destroy(i);
    pool1.destroy(j);
}


struct struct_pool {
    int a;
    bool b;
    // ...
};
typedef boost::singleton_pool<struct_pool, sizeof(struct_pool)> singleton_struct_pool;

struct int_pool {

};
typedef boost::singleton_pool<struct_pool, sizeof(int)> singleton_int_pool;

auto Pool::SingletonPoolExample() -> void
{
    {
        int* i = static_cast<int*>(singleton_int_pool::malloc());
        *i = 1;
        qDebug() << *i;

        singleton_int_pool::release_memory();

        singleton_int_pool::purge_memory();
    }

    struct_pool* i = static_cast<struct_pool*>(singleton_struct_pool::malloc());
    i->a = 1;
    qDebug() << i->a;

    const int length = 10;
    struct_pool* j = static_cast<struct_pool*>(singleton_struct_pool::ordered_malloc(length));
    j[0].a = 2;
    j[1].a = 3;
    j[2].a = 4;
    j[3].a = 5;
    j[4].a = 6;

    qDebug() << j->a << (j+1)->a << (j+2)->a << (j+3)->a << (j+4)->a;

    singleton_struct_pool::release_memory();

    singleton_struct_pool::purge_memory();
}
