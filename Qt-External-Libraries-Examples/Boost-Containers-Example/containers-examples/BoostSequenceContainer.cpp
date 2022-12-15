#include "./include/BoostSequenceContainer.h"

auto BoostSequenceContainer::exampleBoostArray() -> void
{
    boost::array<int, 3> array;
    array.at(0) = 1;
    array.at(1) = 1;
    array.at(2) = 2;
    array.at(1) = 5;

    try {
        array.at(5) = 5; // index out of range
    } catch (boost::wrapexcept<std::out_of_range> error) {
        qDebug() << error.what();
    }

    for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
        qDebug() << *iterator;
    }
}

auto BoostSequenceContainer::exampleBoostVector() -> void
{
    boost::container::vector<int> vector;
    vector.reserve(5); // capacity = 5, size = 0

    for (int i = 0; i < 6; ++i) {
        qDebug() << "capacity = " << vector.capacity() << "size = " << vector.size();
        vector.push_back(i);
    }

    for (int i = 0; i < 4; ++i) {
        qDebug() << "capacity = " << vector.capacity() << "size = " << vector.size();
        vector.pop_back();
    }

    for (auto iterator = vector.begin(); iterator != vector.end(); iterator++) {
        qDebug() << *iterator;
    }
}

auto BoostSequenceContainer::exampleBoostList() -> void
{
    boost::container::list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.push_back(4);

    for (auto iterator = list.begin(); iterator != list.end(); iterator++) {
        qDebug() << *iterator;
    }
}

auto BoostSequenceContainer::exampleBoostDeque() -> void
{
    boost::container::deque<int> deque;
    deque.push_back(3);
    deque.push_back(6);
    deque.push_back(4);
    deque.push_front(0);

    for (auto iterator = deque.begin(); iterator != deque.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}
