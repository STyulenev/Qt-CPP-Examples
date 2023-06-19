#include "SmartPointers.h"

#include <QDebug>

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>
#include <boost/make_shared.hpp>

auto SmartPointers::SharedPointerExample() -> void
{
    int* value = new int(10);

    boost::shared_ptr<int> value_shared_p {value}; // or = boost::make_shared<int>(10);
    std::shared_ptr<int> value_shared_p_2  {value_shared_p.get()}; // or = std::make_shared<int>(10);

    qDebug() << "Adress: " << value_shared_p.get()  << "Value: " << *value_shared_p.get();
    qDebug() << "Adress: " << value_shared_p_2.get() << "Value: " << *value_shared_p_2.get();

    qDebug() << "Count: " << value_shared_p.use_count();

    {
        boost::shared_ptr<int> value_ptr3 {value_shared_p};
        qDebug() << "Count: " << value_ptr3.use_count();
    }

    qDebug() << "Count: " << value_shared_p.use_count();
}

auto SmartPointers::ScopedPointerExample() -> void
{
    int* value = new int(10);

    boost::scoped_ptr<int> value_scoped_p {value}; // or {new int(10)};
    std::unique_ptr<int> value_unique_p {value};   // or {new int(10)};

    // boost::scoped_ptr<int> value_ptr4 = boost::move(value_ptr); - error
    // std::unique_ptr<int> value_ptr3 = std::move(value_ptr2); - ok

    // boost::scoped_ptr<int> value_ptr2 {value_ptr}; - error
    // std::unique_ptr<int> value_ptr2 {value_ptr}; - error

    qDebug() << "Adress: " << value_scoped_p.get()  << "Value: " << *value_scoped_p.get();

    value_scoped_p.reset();
    // qDebug() << "Adress: " << value_ptr.get()  << "Value: " << *value_ptr.get(); - error

    value_scoped_p.reset(value);
    qDebug() << "Adress: " << value_scoped_p.get()  << "Value: " << *value_scoped_p.get();
}

auto SmartPointers::WeakPointerExample() -> void
{
    boost::weak_ptr<int> value_weak_p;
    {
        int* value = new int(10);
        boost::shared_ptr<int> value_shared_p {value}; // or = boost::make_shared<int>(10);
        value_weak_p = value_shared_p;

        if (!value_weak_p.empty()) {
            qDebug() << "Count: " << value_weak_p.use_count();

            {
                boost::shared_ptr<int> value_shared_p_2 {value_weak_p.lock()};
                qDebug() << "Count: " << value_shared_p_2.use_count();
                qDebug() << "Count: " << value_weak_p.use_count();
            }

            qDebug() << "Count: " << value_weak_p.use_count();
        }

        value_weak_p.reset(); // delete pointer

        if (!value_weak_p.empty()) {
            qDebug() << "Count: " << value_weak_p.use_count();
        } else {
            qDebug() << "Count: null";
        }

        value_weak_p = value_shared_p; // create pointer
    }

    if (value_weak_p.lock()) {
        qDebug() << "The resource is still here and can be used";
    } else {
        qDebug() << "The resource is no longer here";
    }
}
