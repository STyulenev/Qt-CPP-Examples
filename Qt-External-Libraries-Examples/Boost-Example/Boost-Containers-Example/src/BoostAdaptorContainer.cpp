#include "BoostAdaptorContainer.h"

#include <boost/container/flat_set.hpp> // flat_set и flat_multiset
#include <boost/container/flat_map.hpp> // flat_map и flat_multimap

auto BoostAdaptorContainer::exampleBoostFlatSet() -> void
{
    boost::container::flat_set<int> flat_set;
    flat_set.insert(2);
    flat_set.insert(3);
    flat_set.insert(1);
    flat_set.insert(3);

    boost::container::flat_set<int>::iterator iterator;

    for (iterator = flat_set.begin(); iterator != flat_set.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}

auto BoostAdaptorContainer::exampleBoostFlatMultiSet() -> void
{
    boost::container::flat_multiset<int> flat_multiset;
    flat_multiset.insert(2);
    flat_multiset.insert(3);
    flat_multiset.insert(1);
    flat_multiset.insert(3);

    boost::container::flat_set<int>::iterator iterator;

    for (iterator = flat_multiset.begin(); iterator != flat_multiset.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}

auto BoostAdaptorContainer::exampleBoostFlatMap() -> void
{
    boost::container::flat_map<int, std::string> flat_map;
    flat_map.insert(std::make_pair(8, std::string("str")));
    flat_map.insert(std::make_pair(9, std::string("str")));
    flat_map.insert(std::make_pair(7, std::string("str")));
    flat_map.insert(std::make_pair(7, std::string("str2")));

    boost::container::flat_map<int, std::string>::iterator iterator;

    for (iterator = flat_map.begin(); iterator != flat_map.end(); iterator++) {
        //std::pair<int, std::string> pair = *iterator;
        //qDebug() <<  pair.first << pair.second.c_str();
        qDebug() <<  (*iterator).first << (*iterator).second.c_str();
    }
}

auto BoostAdaptorContainer::exampleBoostFlatMultiMap() -> void
{
    boost::container::flat_multimap<int, std::string> flat_multimap;
    flat_multimap.insert(std::make_pair(8, std::string("str")));
    flat_multimap.insert(std::make_pair(9, std::string("str")));
    flat_multimap.insert(std::make_pair(7, std::string("str")));
    flat_multimap.insert(std::make_pair(7, std::string("str2")));

    boost::container::flat_multimap<int, std::string>::iterator iterator;

    for (iterator = flat_multimap.begin(); iterator != flat_multimap.end(); iterator++) {
        //std::pair<int, std::string> pair = *iterator;
        //qDebug() <<  pair.first << pair.second.c_str();
        qDebug() <<  (*iterator).first << (*iterator).second.c_str();
    }
}
