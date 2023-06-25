#pragma once

#include <QDebug>

/*!
 * \brief Пример использования библиотеки Boost.Container (контейнеры-адапторы)
 * \details
 * Контейнеры-адапторы:
 * - boost::flat_set (set + vector)
 * - boost::flat_multiset (multiset + vector)
 * - boost::flat_map (map + vector)
 * - boost::flat_multimap (multimap + vector)
 */
class BoostAdaptorContainer
{
private:
    BoostAdaptorContainer() = default;
    ~BoostAdaptorContainer() = default;

public:
    /*!
     * \brief Пример использования boost::flat_set (set + vector)
     * \details
     * Заголовочный файл - #include <boost/container/flat_set.hpp>
     *
     * Описание:
     * - Хранит сортированные уникальные значения
     * - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatSet() -> void;

    /*!
     * \brief Пример использования boost::flat_multiset (multiset + vector)
     * \details
     * Заголовочный файл - #include <boost/container/flat_set.hpp>
     *
     * Описание:
     * - Хранит сортированные неуникальные значения
     * - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatMultiSet() -> void;

    /*!
     * \brief Пример использования boost::flat_map (map + vector)
     * \details
     * Заголовочный файл - #include <boost/container/flat_map.hpp>
     *
     * Описание:
     * - Хранит сортированные уникальные пары ключ-значения
     * - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatMap() -> void;

    /*!
     * \brief Пример использования boost::flat_multimap (multimap + vector)
     * \details
     * Заголовочный файл - #include <boost/container/flat_map.hpp>
     *
     * Описание:
     * - Хранит сортированные неуникальные пары ключ-значения
     * - Данные хранятся в виде вектора с произвольный доступом
     */
    static auto exampleBoostFlatMultiMap() -> void;
};

