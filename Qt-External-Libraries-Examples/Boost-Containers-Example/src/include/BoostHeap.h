#pragma once

#include <QDebug>

/*!
 * \brief Пример использования Boost.Heap
 * \details
 * Boost.Heap предоставляет несколько приоритетных очередей. Однако приоритетные очереди в Boost.Heap отличаются от std::priority_queue тем,
 * что поддерживают больше функций.
 */
class BoostHeap
{
private:
    BoostHeap() = default;
    ~BoostHeap() = default;

public:
    /*!
     * \brief Пример использования boost::heap::priority_queue
     * \details
     * Заголовочный файл - #include <boost/heap/priority_queue.hpp>
     *
     * boost::heap::priority_queue ведет себя как std::priority_queue, за исключением того, что он позволяет перебирать элементы. Порядок элементов,
     * возвращаемых в итерации, является случайным. priority_queue также может называться очередью приоритета повышения. Очереди с приоритетом — это
     * не что иное, как очереди, которые хранят данные/значение в порядке приоритета.
     */
    static auto exampleBoostPriorityQueue() -> void;

    /*!
     * \brief Пример использования boost::heap::binomial_heap
     * \details
     * Заголовочный файл - #include <boost/heap/binomial_heap.hpp>
     *
     * В дополнение ко всем функциям и свойствам, которые предоставляет boost::heap::priority_queue, они имеют еще больше преимуществ,
     * таких как объединение двух приоритетных очередей, изменение элемента в определенной позиции и многие другие полезные функции.
     */
    static auto exampleBoostBinomialHeap() -> void;

    /*!
     * \brief Пример использования boost::heap::fibonacci_heap
     * \details
     * Заголовочный файл - #include <boost/heap/fibonacci_heap.hpp>
     *
     * fibonacci_heap принимает функтор сравнения, который фактически представляет собой struct или class с оператором вызова функции - operator().
     * Функция push() binomial_heap имеет логарифмическую временную сложность, тогда как сложность fibonacci_heap постоянна.
     */
    static auto exampleBoostFibonacciHeap() -> void;
};

