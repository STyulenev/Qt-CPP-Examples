#include "./include/BoostAssociativeContainer.h"

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
    //То же, что и map, но позволяет хранить повторяющиеся элементы.
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
