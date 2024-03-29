#pragma once

#include <QDebug>

/*!
 * \brief Пример использования библиотеки Boost.Container (последовательные контейнеры)
 * \details
 * Последовательные контейнеры:
 * - boost::array – это массив фиксированного размера. Первый шаблонный параметр boost::array является типом элемента, а второй – это размер массива.
 * - boost::vector - это векторный контейнер, который представляет собой массив, подобный контейнеру, который хранит значения в непрерывном блоке памяти.
 * Основное преимущество векторного контейнера заключается в том, что он является динамическим по своей природе, что означает, что он может автоматически
 * изменять размер в зависимости от количества вставленных элементов. Отличается от std::vector при работе с <bool>.
 * - boost::slist — это реализация односвязного списка. Связный список похож на массив, за исключением того факта, что они не имеют непрерывного блока
 * памяти, что приводит к постоянному времени для вставки и удаления, но для обхода списка требуется линейное время.
 * - boost::list - это двухсвязный список, где каждый элемент имеет указатели на предыдущий и последовательный элемент. Благодаря чему мы можем перемещаться
 * по списку как вперед, так и назад.
 * - boost::deque - vector + list
 * - boost::static_vector - vector + array
 * - boost::small_vector - static_vector + vector
 * - boost::devector - vector + deque
 * - boost::stable_vector - vector + list
 * - boost::circular_buffer - кольцевой массив
 */
class BoostSequenceContainer
{
private:
    BoostSequenceContainer() = default;
    ~BoostSequenceContainer() = default;

public:
    /*!
     * \brief Пример использования boost::array
     * \details
     * boost::array ~ std::array
     *
     * Заголовочный файл - #include <boost/array.hpp>
     *
     * Описание:
     * - Статический массив с жёстко заданным количеством элементов.
     * - Данные хранятся в памяти последовательно.
     * - Доступ к элементу по индексу O(1), поиск перебором O(N)
     * - Удаление и вставка нового элемента недоступны, только изменение существующих.
     */
    static auto exampleBoostArray() -> void;

    /*!
     * \brief Пример использования boost::vector
     * \details
     * boost::vector ~ std::vector
     *
     * Заголовочный файл - #include <boost/container/vector.hpp>
     *
     * Описание:
     * - Динамический массив.
     * - Данные хранятся в памяти последовательно, если последовательной памяти недостаточно вектор переписывается в другое место.
     * - При переполнении, ёмкость (capacity) увеличивается в 0.5 раз (не в 2 раза, как в std::vector), а при удалении элементов не изменяется.
     * - Скорость поиска перебором O(N), O(1) - если мы знаем номер элемента.
     */
    static auto exampleBoostVector() -> void;

    /*!
     * \brief Пример использования boost::slist
     * \details
     * boost::slist ~ std::forward_list
     *
     * Заголовочный файл - #include <boost/container/slist.hpp>
     *
     * Описание:
     * - Хранение в виде односвязного списка
     * - Добавление в начало O(1)
     * - Добавление в конец O(1)
     * - Удаление с конца O(n)
     * - Удаление с начала O(1)
     * - Вставка элемента O(n)
     * - Удаление промежуточных элементов O(n)
     * - Доступ к элементу O(n)
     * - Скорость поиска O(N)
     */
    static auto exampleBoostSList() -> void;

    /*!
     * \brief Пример использования boost::list
     * \details
     * boost::list ~ std::list
     *
     * Заголовочный файл - #include <boost/container/list.hpp>
     *
     * Описание:
     * - Хранение в виде двухсвязного списка.
     * - Добавление в начало O(1)
     * - Добавление в конец O(1)
     * - Удаление с конца O(n)
     * - Удаление с начала O(1)
     * - Вставка элемента O(n)
     * - Удаление промежуточных элементов O(n)
     * - Доступ к элементу O(n)
     * - Скорость поиска O(N)
     */
    static auto exampleBoostList() -> void;

    /*!
     * \brief Пример использования boost::deque (vector + list)
     * \details
     * boost::deque ~ std::deque
     *
     * Заголовочный файл - #include <boost/container/deque.hpp>
     *
     * Описание:
     * - Динамический массив двухсвязных списков.
     * - Добавить элемент в начало или конец дека O(1).
     * - Извлечь элемент из начала или конца дека O(1).
     * - Проверить, пуст ли дек O(1).
     * - В отличием от vector, deque поддерживает вставку и удаление элементов с постоянным временем в начале последовательности
     */
    static auto exampleBoostDeque() -> void;

    /*!
     * \brief Пример использования boost::static_vector (vector + array)
     * \details
     * Заголовочный файл - #include <boost/container/static_vector.hpp>
     *
     * Этот контейнер ведет себя как обычный vector, но память у него аллоцирована на стеке под N объектов.
     */
    static auto exampleBoostStaticVector() -> void;

    /*!
     * \brief Пример использования boost::small_vector (static_vector + vector)
     * \details
     * Заголовочный файл - #include <boost/container/small_vector.hpp>
     *
     * В нем статически отводится память под N объектов, но при переполнении аллоцируется память в куче.
     * Этот контейнер хорош, если количество объектов с большой вероятностью не превосходит заранее известное число.
     */
    static auto exampleBoostSmallVector() -> void;

    /*!
     * \brief Пример использования boost::devector (vector + deque)
     * \details
     * Заголовочный файл - #include <boost/container/devector.hpp>
     *
     * В этом контейнере есть быстрая вставка в начало и в конец, как в deque, но при этом сохраняются свойства vector,
     * в частности непрерывный участок памяти и условия инвалидации указателей/итераторов.
     */
    static auto exampleBoostDeVector() -> void;

    /*!
     * \brief Пример использования boost::stable_vector (vector + list)
     * \details
     * Заголовочный файл - #include <boost/container/stable_vector.hpp>
     *
     * Там, где у std::vector лежат объекты, у boost::stable_vector вместо них лежит массив со ссылками на node.
     * node содержит в себе value - сам объект, и up - обратную ссылку на место в массиве, чье значение указывает на node.
     */
    static auto exampleBoostStableVector() -> void;

    /*!
     * \brief Пример использования boost::circular_buffer
     * \details
     * Заголовочный файл - #include <boost/circular_buffer.hpp>
     *
     * В C++ его можно реализовать в виде контейнера фиксированной длины N (на стеке или в куче),
     * где при выходе за границу массива объект создается в начале массива.
     */
    static auto exampleBoostCircularBuffer() -> void;

};

