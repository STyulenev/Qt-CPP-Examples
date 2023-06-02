#include "BoostAssociativeContainer.h"

#include <boost/container/set.hpp> // set и multiset
#include <boost/container/map.hpp> // map и multimap
#include <boost/unordered_set.hpp> // unordered_set и unordered_multiset
#include <boost/unordered_map.hpp> // unordered_map и unordered_multimap
#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>

auto BoostAssociativeContainer::exampleBoostSet() -> void
{
    boost::container::set<int> set;
    set.insert(2);
    set.insert(3);
    set.insert(1);
    set.insert(3);

    boost::container::set<int>::iterator iterator;

    for (iterator = set.begin(); iterator != set.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}

auto BoostAssociativeContainer::exampleBoostMultiSet() -> void
{
    boost::container::multiset<int> multiset;
    multiset.insert(2);
    multiset.insert(3);
    multiset.insert(1);
    multiset.insert(3);

    boost::container::multiset<int>::iterator iterator;

    for (iterator = multiset.begin(); iterator != multiset.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}

auto BoostAssociativeContainer::exampleBoostMap() -> void
{
    boost::container::map<int, std::string> map;
    auto result = map.insert(std::make_pair(8, std::string("str"))); // insert - возвращает итератор с парой клю-значение и bool результат операции

    qDebug() << QString("pair<%1, %2> status: %3").arg((*result.first).first).arg((*result.first).second.c_str()).arg(result.second ? "true" : "false");

    map.insert(std::make_pair(9, std::string("str")));
    map.insert(std::make_pair(7, std::string("str")));
    map.insert(std::make_pair(7, std::string("str2")));

    boost::container::map<int, std::string>::iterator iterator;

    for (iterator = map.begin(); iterator != map.end(); iterator++) {
        //std::pair<int, std::string> pair = *iterator;
        //qDebug() <<  pair.first << pair.second.c_str();
        qDebug() <<  (*iterator).first << (*iterator).second.c_str();
    }
}

auto BoostAssociativeContainer::exampleBoostMultiMap() -> void
{
    boost::container::multimap<int, std::string> multimap;

    multimap.insert(std::make_pair(8, std::string("str")));
    multimap.insert(std::make_pair(9, std::string("str")));
    multimap.insert(std::make_pair(7, std::string("str")));
    multimap.insert(std::make_pair(7, std::string("str2")));

    boost::container::map<int, std::string>::iterator iterator;

    for (iterator = multimap.begin(); iterator != multimap.end(); iterator++) {
        //std::pair<int, std::string> pair = *iterator;
        //qDebug() <<  pair.first << pair.second.c_str();
        qDebug() <<  (*iterator).first << (*iterator).second.c_str();
    }
}

auto BoostAssociativeContainer::exampleBoostUnorderedSet() -> void
{
    boost::unordered::unordered_set<int> unordered_set;
    unordered_set.insert(2);
    unordered_set.insert(3);
    unordered_set.insert(1);
    unordered_set.insert(3);

    boost::unordered::unordered_set<int>::iterator iterator;

    for (iterator = unordered_set.begin(); iterator != unordered_set.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}

auto BoostAssociativeContainer::exampleBoostUnorderedMultiSet() -> void
{
    boost::unordered::unordered_multiset<int> unordered_multiset;
    unordered_multiset.insert(2);
    unordered_multiset.insert(3);
    unordered_multiset.insert(1);
    unordered_multiset.insert(3);

    boost::unordered::unordered_multiset<int>::iterator iterator;

    for (iterator = unordered_multiset.begin(); iterator != unordered_multiset.end(); iterator++) {
        qDebug() <<  *iterator;
    }
}

auto BoostAssociativeContainer::exampleBoostUnorderedMap() -> void
{
    boost::unordered::unordered_map<int, std::string> unordered_map;

    unordered_map.insert(std::make_pair(8, std::string("str")));
    unordered_map.insert(std::make_pair(9, std::string("str")));
    unordered_map.insert(std::make_pair(7, std::string("str")));
    unordered_map.insert(std::make_pair(7, std::string("str2")));

    boost::unordered::unordered_map<int, std::string>::iterator iterator;

    for (iterator = unordered_map.begin(); iterator != unordered_map.end(); iterator++) {
        qDebug() <<  (*iterator).first << (*iterator).second.c_str();
    }
}

auto BoostAssociativeContainer::exampleBoostUnorderedMultiMap() -> void
{
    boost::unordered::unordered_multimap<int, std::string> unordered_multimap;

    unordered_multimap.insert(std::make_pair(8, std::string("str")));
    unordered_multimap.insert(std::make_pair(9, std::string("str")));
    unordered_multimap.insert(std::make_pair(7, std::string("str")));
    unordered_multimap.insert(std::make_pair(7, std::string("str2")));

    boost::unordered::unordered_multimap<int, std::string>::iterator iterator;

    for (iterator = unordered_multimap.begin(); iterator != unordered_multimap.end(); iterator++) {
        qDebug() <<  (*iterator).first << (*iterator).second.c_str();
    }
}

auto BoostAssociativeContainer::exampleBoostBimap() -> void
{
    // boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::set_of<int>> bimap
    boost::bimap<std::string, int> bimap;

    bimap.insert({"first",  1});
    bimap.insert({"second", 2});
    bimap.insert({"third",  3});
    bimap.insert({"third",  3});
    bimap.insert({"fourth", 3});

    qDebug() << "size =" << bimap.size();

    qDebug() << bimap.left.count("third");
    qDebug() << bimap.right.count(3);
    //qDebug() << bimap.right.equal_range();

    for (auto iterator = bimap.begin(); iterator != bimap.end(); ++iterator)
        qDebug() << "key" << iterator->left.c_str() << "value" << iterator->right;
}

auto BoostAssociativeContainer::exampleBoostMultiBimap() -> void
{
    { // неуникальное правое значение
        boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::multiset_of<int>> multibimap;

        multibimap.insert({"first",  1});
        multibimap.insert({"second", 2});
        multibimap.insert({"third",  3});
        multibimap.insert({"third",  3});
        multibimap.insert({"fourth", 3});

        qDebug() << "size =" << multibimap.size();

        qDebug() << multibimap.left.count("third");
        qDebug() << multibimap.right.count(3);
        //qDebug() << bimap.right.equal_range();

        for (auto iterator = multibimap.begin(); iterator != multibimap.end(); ++iterator)
            qDebug() << "key" << iterator->left.c_str() << "value" << iterator->right;
    }

    { // неуникальные и ключ, и значение
        boost::bimap<boost::bimaps::multiset_of<std::string>, boost::bimaps::multiset_of<int>> multibimap;

        multibimap.insert({"first",  1});
        multibimap.insert({"second", 2});
        multibimap.insert({"third",  3});
        multibimap.insert({"third",  3});
        multibimap.insert({"fourth", 3});

        qDebug() << "size =" << multibimap.size();

        qDebug() << multibimap.left.count("third");
        qDebug() << multibimap.right.count(3);
        //qDebug() << bimap.right.equal_range();

        for (auto iterator = multibimap.begin(); iterator != multibimap.end(); ++iterator)
            qDebug() << "key" << iterator->left.c_str() << "value" << iterator->right;
    }
}
