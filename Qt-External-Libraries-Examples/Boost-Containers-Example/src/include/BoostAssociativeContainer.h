#pragma once

#include <QDebug>

/*!
 * \brief Класс с примерами использования ассоциативных и unordered ассоциативных boost-контейнеров.
 * \details
 * Ассоциативные контейнеры (ключ+значение):
 * - boost::set — это контейнер, в котором хранятся отсортированные и уникальные элементы.
 * - boost::multiset
 * - boost::map — это контейнер, в котором хранятся отсортированные и уникальные пары ключ-значение.
 * - boost::multimap
 * - boost::unordered_set
 * - boost::unordered_multiset
 * - boost::unordered_map
 * - boost::unordered_multimap
 * - boost::bimap - основана на boost::multi_index и предоставляет контейнер, который можно использовать сразу, без предварительного определения.
 * Контейнер похож на std::map/boost::map, но поддерживает поиск значений с любой стороны. boost::bimap позволяет создавать карты, где любая сторона
 * может быть ключевой, в зависимости от того, как вы получаете доступ к карте. Когда вы обращаетесь к левой стороне как к ключу, правая сторона
 * является значением, и наоборот.
 *
 * boost::bimap спецификаторы:
 * - boost::bimaps::set_of - уникальный ключ и/или значение (стоит по умолчанию)
 * - boost::bimaps::multiset_of - неуникальный ключ и/или значение
 * - boost::bimaps::unordered_set_of - делает аналог boost::unordered_set
 * - boost::bimaps::unordered_multiset_of - делает аналог boost::unordered_multiset
 * - boost::bimaps::list_of - делает аналог boost::list
 * - boost::bimaps::vector_of - делает аналог boost::vector
 * - boost::bimaps::unconstrained_set_of - это представление без ограничений
 *
 * Заметки:
 * - Добавление unordered означает, что элементы не отсортированы и хранятся в хэш-таблице
 * - Добавление multi означает, что разрешено хранение повторяющихся элементов.
 *
 * set vs map:
 * - Наборы и карты обычно внутренне реализованы как красно-черные деревья, которые представляют собой сбалансированные бинарные деревья поиска
 * - И наборы, и карты имеют ключ и значение, ключ используется для индексации контейнера
 * - set::value_type набора совпадает с ключом для набора
 * - map::value_type представляет собой пару std::pair из ключа и значения
 * - Набор можно заставить функционировать как карта, создав набор пар как, std::set<std::pair<int, int>который похож на std::map<int, int>,
 * хотя карта будет предпочтительнее, поскольку агрегация по ключам и сортировка будут реализованы более эффективно
 *
 */
class BoostAssociativeContainer
{
public:
    /*!
     * \brief Пример использования boost::set
     * \details
     * boost::set ~ std::set
     *
     * Заголовочный файл - #include <boost/container/set.hpp>
     *
     * Описание:
     * - Хранит уникальные отсортированные значения
     * - Данные хранятся в виде бинарного дерева поиска
     * - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostSet() -> void;

    /*!
     * \brief Пример использования boost::multiset
     * \details
     * boost::multiset ~ std::multiset
     *
     * Заголовочный файл - #include <boost/container/set.hpp>
     *
     * Описание:
     * - Хранит неуникальные отсортированные значения
     * - Данные хранятся в виде бинарного дерева поиска
     * - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostMultiSet() -> void;

    /*!
     * \brief Пример использования boost::map
     * \details
     * boost::map ~ std::map
     *
     * Заголовочный файл - #include <boost/container/map.hpp>
     *
     * Описание:
     * - Хранит пару ключ-значение
     * - Хранит только уникальные ключи, значения могут быть одинаковые
     * - Данные отсортированны по ключам
     * - Данные хранятся в виде бинарного дерева
     * - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostMap() -> void;

    /*!
     * \brief Пример использования boost::multimap
     * \details
     * boost::multimap ~ std::multimap
     *
     * Заголовочный файл - #include <boost/container/map.hpp>
     *
     * Описание:
     * - Хранит пару ключ-значение
     * - Хранит неуникальные ключи, в отличие от map
     * - Данные отсортированны по ключам
     * - Данные хранятся в виде бинарного дерева
     * - Скорость поиска, вставки, удаления O(Log(N))
     */
    static auto exampleBoostMultiMap() -> void;

    /*!
     * \brief Пример использования boost::unordered_set
     * \details
     * boost::unordered_set ~ std::unordered_set
     *
     * Заголовочный файл - #include <boost/unordered_set.hpp>
     *
     * Описание:
     * - Хранит уникальные неотсортированные значения
     * - Данные хранятся в виде хэш-таблицы
     * - Скорость поиска, вставки, удаления O(1)
     */
    static auto exampleBoostUnorderedSet() -> void;

    /*!
     * \brief Пример использования boost::unordered_multiset
     * \details
     * boost::unordered_multiset ~ std::unordered_multiset
     *
     * Заголовочный файл - #include <boost/unordered_set.hpp>
     *
     * Описание:
     * - Хранит неуникальные неотсортированные значения
     * - Данные хранятся в виде хэш-таблицы
     * - Скорость поиска, вставки, удаления O(1), O(N) - если несколько одинаковых значений, то происходит перебор
     */
    static auto exampleBoostUnorderedMultiSet() -> void;

    /*!
     * \brief Пример использования boost::unordered_map
     * \details
     * boost::unordered_map ~ std::unordered_map
     *
     * Заголовочный файл - #include <boost/unordered_map.hpp>
     *
     * Описание:
     * - Хранит пару ключ-значение
     * - Хранит только уникальные ключи, значения могут быть одинаковые
     * - Данные отсортированны по ключам
     * - Данные хранятся в виде хэш-таблицы
     * - Скорость поиска, вставки, удаления O(Log(1))
     */
    static auto exampleBoostUnorderedMap() -> void;

    /*!
     * \brief Пример использования boost::unordered_multimap
     * \details
     * boost::unordered_multimap ~ std::unordered_multimap
     *
     * Заголовочный файл - #include <boost/unordered_map.hpp>
     *
     * Описание:
     * - Хранит пару ключ-значение
     * - Хранит неуникальные ключи, в отличие от map
     * - Данные отсортированны по ключам
     * - Данные хранятся в виде хэш-таблицы
     * - Скорость поиска, вставки, удаления O(1), O(N) - если несколько одинаковых значений, то происходит перебор
     */
    static auto exampleBoostUnorderedMultiMap() -> void;

    /*!
     * \brief Пример использования boost::bimap (boost::bimaps::set_of)
     * \details
     * boost::bimap ~ std::map/boost::map
     *
     * Заголовочный файлы:
     * - #include <boost/bimap.hpp>
     * - #include <boost/bimap/set_of.hpp> // необязательно
     *
     * Уникальные и ключ, и значение
     */
    static auto exampleBoostBimap() -> void;

    /*!
     * \brief Пример использования boost::bimap с boost::bimaps::multiset_of
     * \details
     * boost::bimap ~ std::multimap/boost::multimap
     *
     * Заголовочный файл:
     * - #include <boost/bimap.hpp>
     * - #include <boost/bimap/multiset_of.hpp>
     *
     * Можно сделать неуникальным ключ, значение или ключ и значение
     */
    static auto exampleBoostMultiBimap() -> void;

};

