#pragma once

#include <QDebug>

/*!
 * \brief Примеры использования библиотеки Boost.Range
 * \details
 * Boost.Range:
 * - Алгоритмы
 * - Адапторы
 * - Вспомогательные классы и функции
 *
 * В отличие от Boost.Algorithm, в Boost.Range не нужно передавать .begin() и .end(), а сразу контейнер. Любой контейнер, имеющий .begin() и .end()
 * может считаться диапазоном. Большинство алгоритмов из Boost.Algorithm подходит для использования диапазонов, вместо .begin() и .end().
 */
class BoostRange
{
private:
    BoostRange() = default;
    ~BoostRange() = default;

public:
    /*!
     * \brief Примеры использования алгоритмов для диапазонов
     * \details
     * Заголовочный файл - #include <boost/range/algorithm.hpp>
     *
     * Алгоритмы:
     * - adjacent_find - находит одинаковый соседний элемент из диапазона
     * - binary_search - функция проверяет, находится ли элемент, эквивалентный значению, в диапазоне [first, last]. Требования к бинарному поиску:
     * Разделение по отношению к элементу < значение.
     * - copy - функция копирует все элементы из исходного диапазона в целевой диапазон [начало, начало + расстояние (исходный массив)].
     * - copy_backward - функция копирует элементы из диапазона, определенного [first, last], в конец другого диапазона. Элементы копируются в
     * обратном порядке (последний элемент копируется первым), но их относительный порядок сохраняется. Целевой диапазон должен иметь допустимый размер,
     * иначе возникнет неопределенное поведение.
     * - count - посчитать кол-во элементов
     * - count_if - посчитать кол-во элементов с условием (в виде унарного предиката)
     * - equal - сравнивает диапазону, если разные длины, то сразу false
     * - equal_range - это версия бинарного поиска: он пытается найти значение элемента в упорядоченном диапазоне [first, last)
     * - fill - функция инициализирует все элементы массива желаемым значением диапазона
     * - fill_n - функции для заполнения поддиапазона у диапазона
     * - find - функция возвращает итератор к первому вхождению элемента в диапазоне [first, last], который сравнивает operator== (равно) с val.
     * Если в диапазоне не найден ни один элемент, функция возвращает последний из последовательности.
     * - find_end - функция возвращает итератор к последнему вхождению последовательности range2 в range1 [first, last]
     * - find_first_of - находит элемент из набора в диапазоне
     * - find_if - находит итератор первого элемента, который выполняет условие предиката
     * - for_each - функция проходит вперед по диапазону range и для каждого элемента вызывает функцию/предикат
     * - generate - функция генерирует значение для диапазона с помощью функции, т. е. присваивает значение
     * - heap_algorithm - алгоритмы диапазона для Boost.Heap (push_heap - добавить, pop_heap - убрать, make_heap - сделать heap, sort_heap - сортировать)
     * - inplace_merge - функция объединяет два последовательных отсортированных диапазона в один отсортированный диапазон
     * - lexicographical_compare - функция проверяет, меньше ли первый диапазон лексикографически, чем второй диапазон
     * - lower_bound - функция возвращает итератор к первому вхождению элемента в диапазоне [first, last], который сравнивается не меньше, чем val
     * - max_element - функция возвращает итератор к первому вхождению элемента в диапазоне [first, last], который является наибольшим в диапазоне
     * - merge - функция объединяет два последовательных отсортированных диапазона в один отсортированный диапазон.
     * Эта функция устойчива, т. е. сохраняется относительный порядок элементов в диапазоне
     * -  min_element - функция возвращает итератор к первому вхождению элемента в диапазоне [first, last], который является наименьшим в диапазоне
     * - mismatch - находит первую позицию, в которой соответствующие элементы из двух диапазонов не равны, иначе 0
     * - nth_element -функция не сортирует массив точно, а разделяет элементы таким образом, что все элементы, предшествующие n-му элементу
     * (элемент, встречающийся в позиции n после сортировки массива), будут меньше или равны n и всем элементам, следующим за n-м элементом.
     * будет больше или равно n-му элементу
     * - partial_sort - функция переставляет элементы в диапазоне. Он размещает элементы в неубывающем (или невозрастающем) порядке от [начало, середина],
     * а остальные элементы, т.е. [середина, конец], размещаются без какого-либо определенного порядка.
     * - partition - функция упорядочивает последовательность на основе некоторого предиката, так что элементы, возвращающие истину для предиката,
     * предшествуют точке разделения, т.е. середине, а элементы, возвращающие ложь для предиката, следуют за точкой разделения
     * - permutation - генерирует перестановки последовательности в лексикографическом порядке (next_permutation) или нет (prev_permutation)
     * - random_shuffle - функция случайным образом изменяет последовательность
     * - remove - оболочка для std::remove(). Элементы во входном диапазоне переупорядочиваются, но размер входного контейнера не изменяется.
     * Возвращается итератор нового конца.
     * - remove_copy - функция удаляет все вхождения из последовательности, так что элементы x из диапазона возвращают true для x == val,
     * и копирует элемент в выходной итератор
     * remove_copy_if - функция удаляет все вхождения из последовательности, так что элементы x из диапазона возвращают true для некоторого предиката,
     * и копирует остальные элементы (для которых предикат возвращает false) в выходной итератор
     * - remove_if - флементы во входном диапазоне переупорядочиваются, но размер входного контейнера не меняется. Возвращается итератор нового конца
     * - replace - функция заменяет все вхождения элементов в диапазлон, равных некоторому значению, на новое значение
     * - replace_copy - делает всё как replace, только ещё и копирует результат не изменяя первый диапазон
     * - replace_copy_if - делает всё как replace_copy, но следуюет некоторому условию
     * - replace_if - делает всё как replace, но следуюет некоторому условию
     * - reverse - функция меняет порядок элементов в диапазоне на обратный
     * - reverse_copy - тоже самое что reverse, только результат копирует в другой диапазон
     * - rotate - функция вращает последовательность [first, last] таким образом, что средний элемент, переданный в качестве параметра,
     * становится новым первым в последовательности
     * - rotate_copy - тоже самое что rotate, только результат копирует в другой диапазон
     * - search - функция возвращает итератор к первому вхождению одного диапазона внутри другого. Если значение не найдено, возвращается конечный итератор
     * - search_n - Возвращаем итератор к первому вхождению повторяющихся элементов внутри диапазон. Повторяющиеся элементы передаются как аргументы
     * счетчика/значения
     * - set_algorithm - операции со множествами
     * - sort - сортировка по возрастанию
     * - stable_partition - переупорядочивает входной диапазон так, что все элементы,  для которых функция предиката имеет значение true, идут первыми.
     * Все остальные идут вторыми
     * - swap_ranges - меняет два диапазона
     * - transform - применяет унарный предикат к каждому элементу входного диапазона и записывает результат в выходной итератор
     * - unique - Элементы во входном диапазоне переупорядочиваются, но размер входного контейнера не изменяется. Возвращает диапазон [begin, unique_end]
     *  по умолчанию, где unique_end указывает на единицу после последнего уникального элемента.
     *  - unique_copy - тоже самое что и unique, только ещё и копируется
     *  - upper_bound - Возвращаем итератор, указывающий на первый элемент, который меньше или равен аргументу значения
     */
    static auto exampleBoostRangeAlgorithms() -> void;

    /*!
     * \brief Примеры использования адаптаров
     * \details
     * Заголовочный файл - #include <boost/range/adaptors.hpp>
     *
     * Алгоритмы:
     * - adjacent_filtered
     * - copied - адаптор для копирования части диапазона
     * - filtered - адаптор для фильтрации диапазона
     * - indexed - учитывая диапазон, он дает доступ к элементам, а также к их индексам
     * - indirected - адаптор индексирует диапазон для убоного использования, например, в цикле foreach
     * - map - адапторы map_keys и map_values для работы с ключами/значениями карты
     * - replaced - адаптор для замены элементов диапазона
     * - replaced_if - адаптор replaced с условием
     * - reversed - адаптор для работы с диапазоном в обратном порядке
     * - sliced - адаптор для работы с частью диапазона
     * - strided - адаптор для работы с каждым n-ым элементом
     * - tokenized - адаптор для работы с поддиапазонами
     * - transformed - адаптор для трансформации/изменения диапазона
     * - uniqued - адаптор убирает повторяющиеся подряд элементы диапазона
     */
    static auto exampleBoostRangeAdaptors() -> void;

    /*!
     * \brief Примеры использования расширенных алгоритмов
     * \details
     * Заголовочный файл - #include <boost/range/algorithm_ext.hpp>
     *
     * Алгоритмы:
     * - copy_n - копирует элементы из диапазона, является более безопасным аналогом одноименной функции из #include <boost/range/algorithm.hpp>
     * - erase - удаляет произвольный поддиапазон из диапазона
     * - for_each - выполнить предикат для двух диапазонов
     * - insert - вставка элементов из одного диапазона в другой
     * - iota - заполнить диапазон увеличивающимися + 1 значениями с заданного числа
     * - is_sorted - проверка диапазона на отсортированность по возрастанию
     * - overwrite - копирование диапазона в другой диапазон с перезаписью
     * - push_back - копирует в конец значения из диапазона в другой
     * - push_front - копирует в начало значения из диапазона в другой
     */
    static auto exampleBoostRangeAlgorithmExtensions() -> void;
};

