#include "BoostSequenceContainer.h"

#include <boost/array.hpp>
#include <boost/container/vector.hpp>
#include <boost/container/slist.hpp>
#include <boost/container/list.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/container/small_vector.hpp>
#include <boost/container/devector.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/circular_buffer.hpp>

auto BoostSequenceContainer::exampleBoostArray() -> void
{
    boost::array<int, 3> array;
    array.at(0) = 1;
    array.at(1) = 1;
    array.at(2) = 2;
    array.at(1) = 5;

    try {
        array.at(5) = 5; // index out of range
    } catch (boost::wrapexcept<std::out_of_range>& error) {
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

auto BoostSequenceContainer::exampleBoostSList() -> void
{
    boost::container::slist<int> slist;

    if (slist.empty()) {
        qDebug() << "slist is empty";
    }

    slist.push_front(0);
    slist.push_front(1);
    slist.emplace_front(4);

    for (auto iterator = slist.begin(); iterator != slist.end(); iterator++) {
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
    qDebug() << "size = " << deque.size();
    deque.push_back(3);
    deque.push_back(6);
    deque.push_back(4);
    deque.push_front(0);
    qDebug() << "size = " << deque.size();

    for (auto iterator = deque.begin(); iterator != deque.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}

auto BoostSequenceContainer::exampleBoostStaticVector() -> void
{
    boost::container::static_vector<int, 5> static_vector;
    static_vector.push_back(1);
    static_vector.push_back(2);
    static_vector.push_back(3);
    static_vector.push_back(4);
    static_vector.push_back(5);

    try {
        static_vector.push_back(6); // Переполнение памяти, вылет ошибки std::bad_alloc
    } catch (const std::bad_alloc&) {
        qDebug() << "Ошибка. В статическом векторе превышен лимит кол-ва элементов.";
    }

    for (auto iterator = static_vector.begin(); iterator != static_vector.end(); iterator++) {
        qDebug() << *iterator;
    }

}

auto BoostSequenceContainer::exampleBoostSmallVector() -> void
{
    boost::container::small_vector<int, 5> small_vector;
    small_vector.push_back(1);
    small_vector.push_back(2);
    small_vector.push_back(3);
    small_vector.push_back(4);
    small_vector.push_back(5);
    small_vector.push_back(6); // Переполнение памяти, ошибки нет, создание элемента в куче

    for (auto iterator = small_vector.begin(); iterator != small_vector.end(); iterator++) {
        qDebug() << *iterator;
    }
}

auto BoostSequenceContainer::exampleBoostDeVector() -> void
{
    boost::container::devector<int> devector;
    devector.push_back(1);
    devector.push_back(2);
    devector.push_back(3);
    devector.push_back(4);
    devector.push_back(5);

    qDebug() << "size = " << devector.size();

    while (devector.size() != 0) {
        qDebug() << devector.front();
        devector.pop_front();
    }
}

auto BoostSequenceContainer::exampleBoostStableVector() -> void
{
    boost::container::stable_vector<int> stable_vector(3);
    // лежат в векторе
    stable_vector.at(0) = 1;
    stable_vector.at(1) = 2;
    stable_vector.at(2) = 3;
    // создаются в листе
    stable_vector.push_back(5);
    stable_vector.push_back(6);
    stable_vector.push_back(7);
    stable_vector.push_back(8);

    for (auto iterator = stable_vector.begin(); iterator != stable_vector.end(); iterator++) {
        qDebug() << *iterator;
    }
}

auto BoostSequenceContainer::exampleBoostCircularBuffer() -> void
{
    boost::circular_buffer<int> circular_buffer(5);
    circular_buffer.push_back(5);
    circular_buffer.push_back(6);
    circular_buffer.push_back(7);
    circular_buffer.push_back(8);
    circular_buffer.push_back(9);
    circular_buffer.push_back(10);
    // 5 удалиться из-за перезаписи

    for (auto iterator = circular_buffer.begin(); iterator != circular_buffer.end(); iterator++) {
        qDebug() << *iterator;
    }
}
