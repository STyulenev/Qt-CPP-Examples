#include "PointerContainer.h"

#include <QDebug>

#include <boost/smart_ptr/shared_ptr.hpp>

#include <boost/ptr_container/ptr_array.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_deque.hpp>

#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/ptr_unordered_set.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/ptr_unordered_map.hpp>

auto PointerContainer::PointerVectorExample() -> void
{
    boost::ptr_vector<int> vector;

    vector.push_back(new int(5));
    vector.push_back(new int(6));
    vector.push_back(new int(7));

    int* value = new int(10);
    boost::shared_ptr<int> value_shared_p {value};
    // boost::shared_ptr<int> value_shared_p = vector[2]; - error
    vector.push_back(value_shared_p.get());

    for (auto iterator = vector.begin(); iterator != vector.end(); ++iterator) {
        qDebug() << *iterator;
    }

    vector.pop_back(); // delete last item

    for (auto element : vector) {
        qDebug() << element; // not pointer
    }

    qDebug() << *value_shared_p.get();
}

auto PointerContainer::PointerListExample() -> void
{
    boost::ptr_list<int> list;

    int* value = new int(10);

    list.push_back(value);
    list.push_back(new int(6));
    list.push_front(new int(4));

    delete value;

    // qDebug() << list[1]; - error

    {
        std::shared_ptr<int> value = std::make_shared<int>(std::move(list.front()));
    }

    for (auto element : list) {
        qDebug() << element; // not pointer
    }
}
