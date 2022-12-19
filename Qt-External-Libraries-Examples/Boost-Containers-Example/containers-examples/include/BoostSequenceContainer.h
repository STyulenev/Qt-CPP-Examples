#pragma once

#include <QDebug>

#include <boost/array.hpp>
#include <boost/container/vector.hpp>
#include <boost/container/list.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/container/small_vector.hpp>
#include <boost/thread/csbl/devector.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/circular_buffer.hpp>

/*!
 * \brief Класс с примерами использования последовательных boost-контейнеров.
 */
class BoostSequenceContainer
{
public:
    /*!
     * \brief Пример использования Array.
     * \details
     * 1 - Статический массив с жёстко заданным количеством элементов.
     * 2 - Данные хранятся в памяти последовательно.
     * 3 - Доступ к элементу по индексу O(1), поиск перебором O(N)
     * 4 - Удаление и вставка нового элемента недоступны, только изменение существующих.
     */
    static auto exampleBoostArray() -> void;

    /*!
     * \brief Пример использования Vector.
     * \details
     * 1 - Динамический массив.
     * 1 - Данные хранятся в памяти последовательно, если последовательной памяти недостаточно вектор переписывается в другое место.
     * 2 - При переполнении, ёмкость (capacity) увеличивается в 0.5 раз (не в 2 раза, как в std::vector), а при удалении элементов не изменяется.
     * 3 - Скорость поиска перебором O(N), O(1) - если мы знаем номер элемента.
     */
    static auto exampleBoostVector() -> void;

    /*!
     * \brief Пример использования List.
     * \details
     * 1 - Хранение в виде двухсвязного списка.
     * 2 - Вставка и удаление O(1).
     * 3 - Скорость поиска O(N).
     */
    static auto exampleBoostList() -> void;

    /*!
     * \brief Пример использования Deque (Vector + List).
     * \details
     * 1 - Динамический массив двухсвязных списков.
     * 2 - Добавить элемент в начало или конец дека O(1).
     * 3 - Извлечь элемент из начала или конца дека O(1).
     * 4 - Проверить, пуст ли дек O(1).
     * 5 - В отличием от vector, deque поддерживает вставку и удаление элементов с постоянным временем в начале последовательности
     */
    static auto exampleBoostDeque() -> void;

    /*!
     * \brief StaticVector - гибрид Vector + Array
     * \details Этот контейнер ведет себя как обычный vector, но память у него аллоцирована на стеке под N объектов.
     */
    static auto exampleBoostStaticVector() -> void;

    /*!
     * \brief SmallVector - гибрид static_vector и vector
     * \details В нем статически отводится память под N объектов, но при переполнении аллоцируется память в куче.
     *  Этот контейнер хорош, если количество объектов с большой вероятностью не превосходит заранее известное число.
     */
    static auto exampleBoostSmallVector() -> void;

    /*!
     * \brief DeVector - это гибрид vector и deque.
     * \details В этом контейнере есть быстрая вставка в начало и в конец, как в deque, но при этом сохраняются свойства vector,
     *  в частности непрерывный участок памяти и условия инвалидации указателей/итераторов.
     */
    static auto exampleBoostDeVector() -> void;

    /*!
     * \brief StableVector - это гибрид vector и list.
     * \details Там, где у std::vector лежат объекты, у boost::stable_vector вместо них лежит массив со ссылками на node.
     * node содержит в себе value - сам объект, и up - обратную ссылку на место в массиве, чье значение указывает на node.
     */
    static auto exampleBoostStableVector() -> void;

    /*!
     * \brief CircularBuffer кольцевой массив
     * \details В C++ его можно реализовать в виде контейнера фиксированной длины N (на стеке или в куче),
     * где при выходе за границу массива объект создается в начале массива.
     */
    static auto exampleBoostCircularBuffer() -> void;
};

