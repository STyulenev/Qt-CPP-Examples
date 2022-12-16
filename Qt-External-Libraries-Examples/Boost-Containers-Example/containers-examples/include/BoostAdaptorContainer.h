#pragma once

#include <QDebug>

#include <boost/container/flat_set.hpp> // flat_set и flat_multiset
#include <boost/container/flat_map.hpp> // flat_map и flat_multimap

/*!
 * \brief Класс с примерами использования boost-adaptor.
 */
class BoostAdaptorContainer
{
public:
    /*!
     * \brief FlatSet (set + vector)
     * 1 - Хранит сортированные уникальные значения
     * 2 - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatSet() -> void;
    /*!
     * \brief FlatMultiSet (multiset + vector)
     * 1 - Хранит сортированные неуникальные значения
     * 2 - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatMultiSet() -> void;

    /*!
     * \brief FlatMap (map + vector)
     * 1 - Хранит сортированные уникальные пары ключ-значения
     * 2 - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatMap() -> void;

    /*!
     * \brief FlatMultiMap (multimap + vector)
     * 1 - Хранит сортированные неуникальные пары ключ-значения
     * 2 - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatMultiMap() -> void;
};

