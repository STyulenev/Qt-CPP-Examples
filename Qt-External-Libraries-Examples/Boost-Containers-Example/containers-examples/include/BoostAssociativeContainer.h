#pragma once

#include <QDebug>

#include <boost/container/set.hpp> // set и multiset
#include <boost/container/map.hpp> // map и multimap
#include <boost/unordered_set.hpp> // unordered_set и unordered_multiset
#include <boost/unordered_map.hpp> // unordered_map и unordered_multimap

/*!
 * \brief Класс с примерами использования ассоциативных и unordered ассоциативных boost-контейнеров.
 */
class BoostAssociativeContainer
{
public:
    /*!
     * \brief Set
     * 1 - Хранит уникальные отсортированные значения
     * 2 - Данные хранятся в виде бинарного дерева поиска
     * 3 - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostSet() -> void;

    /*!
     * \brief MultiSet
     * 1 - Хранит неуникальные отсортированные значения
     * 2 - Данные хранятся в виде бинарного дерева поиска
     * 3 - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostMultiSet() -> void;

    /*!
     * \brief Map
     * 1 - Хранит пару ключ-значение
     * 2 - Хранит только уникальные ключи, значения могут быть одинаковые
     * 3 - Данные отсортированны по ключам
     * 4 - Данные хранятся в виде бинарного дерева
     * 5 - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostMap() -> void;

    /*!
     * \brief MultiMap
     * 1 - Хранит пару ключ-значение
     * 2 - Хранит неуникальные ключи, в отличие от map
     * 3 - Данные отсортированны по ключам
     * 4 - Данные хранятся в виде бинарного дерева
     * 5 - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostMultiMap() -> void;

    /*!
     * \brief UnorderedSet
     * 1 - Хранит уникальные неотсортированные значения
     * 2 - Данные хранятся в виде хэш-функции
     * 3 - Скорость поиска, вставки, удаления O(1)
     */
    static auto exampleBoostUnorderedSet() -> void;

    /*!
     * \brief UnorderedMultiSet
     * 1 - Хранит неуникальные неотсортированные значения
     * 2 - Данные хранятся в виде Хэш-таблицы
     * 3 - Скорость поиска, вставки, удаления O(1), O(N) - если несколько одинаковых значений, то происходит перебор
     */
    static auto exampleBoostUnorderedMultiSet() -> void;

    /*!
     * \brief Map
     * 1 - Хранит пару ключ-значение
     * 2 - Хранит только уникальные ключи, значения могут быть одинаковые
     * 3 - Данные отсортированны по ключам
     * 4 - Данные хранятся в виде бинарного дерева
     * 5 - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostUnorderedMap() -> void;

    /*!
     * \brief MultiMap
     * 1 - Хранит пару ключ-значение
     * 2 - Хранит неуникальные ключи, в отличие от map
     * 3 - Данные отсортированны по ключам
     * 4 - Данные хранятся в виде бинарного дерева
     * 5 - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostUnorderedMultiMap() -> void;

};

