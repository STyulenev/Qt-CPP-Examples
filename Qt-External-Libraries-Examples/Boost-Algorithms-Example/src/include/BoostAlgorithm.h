#pragma once

#include <QDebug>

/*!
 * \brief Примеры использования библиотеки Boost.Algorithm
 * \details
 * Boost.Algorithm предоставляет алгоритмы, дополняющие алгоритмы из стандартной библиотеки. В отличие от Boost.Range,
 * Boost.Algorithm не вводит новых концепций. Алгоритмы, определенные Boost.Algorithm, напоминают алгоритмы из стандартной библиотеки.
 */
class BoostAlgorithm
{
private:
    BoostAlgorithm() = default;
    ~BoostAlgorithm() = default;

public:
    /*!
     * \brief Примеры использования алгоритмов поиска подстроки в строке
     * \details
     * Алгоритмы:
     * - Алгоритм Бойера-Мура
     * - Алгоритм Бойера-Мура-Хорспула
     * - Алгоритм Кнута-Морриса-Пратта
     */
    static auto exampleSearchingAlgorithms() -> void;

    /*!
     * \brief Примеры использования алгоритмов добавленных в C++11
     * \details
     * Алгоритмы:
     * - all_of - Алгоритм возвращает true, если все они имеют общее свойство.
     * - any_of - Алгоритм возвращает true, если какой-либо из элементов обладает определенным свойством.
     * - one_of - Алгоритм возвращает значение true, если ровно один из элементов последовательности обладает определенным свойством.
     * - none_of - Алгоритм возвращает true, если ни один из них не имеет общего свойства.
     * - is_sorted - Функция определяет, полностью ли отсортирована последовательность по заданным критериям.
     * - is_partitioned - Алгоритм возвращает true, если все элементы последовательности, удовлетворяющие предикату, находятся в начале последовательности.
     * - is_permutation - Алгоритм проверяет, является ли одна последовательность перестановкой второй.
     * - partition_point - Алгоритм возвращает итератор, который «указывает» на первый элемент в последовательности не удовлетворяющий предикату.
     * - partition_copy - Алгоритм копирует подмножество последовательности в две новые последовательности в зависимости от результата предиката.
     * - copy_if - Алгоритм копирует подмножество в зависимости от условия.
     * - copy_n - Алгоритм копирует подмножество из n элементов.
     * - iota - Алгоритм генерирует возрастающую последовательность.
     */
    static auto exampleCPP11Algorithms() -> void;

    /*!
     * \brief Примеры использования алгоритмов добавленных в C++14
     * \details
     * Алгоритмы:
     * - equal - Алгоритм проверяет, содержат ли две последовательности одинаковые значения.
     * - mismatch - Алгоритм находит первую точку в двух последовательностях, где они не совпадают.
     */
    static auto exampleCPP14Algorithms() -> void;

    /*!
     * \brief Примеры использования алгоритмов добавленных в C++17
     * \details
     * Алгоритмы:
     * - for_each_n - Алгоритм применяет функтор к элементам последовательности.
     * - transform_inclusive_scan - Алгоритм применяет функтор к элементам последовательности и одновременно к диапазону от нулевого элемента до текущего.
     * - transform_exclusive_scan - Тоже самое, что и transform_inclusive_scan, но i-ый элемент не участвует в операции.
     */
    static auto exampleCPP17Algorithms() -> void;

    /*!
     * \brief Примеры использования алгоритмов копирования
     * \details
     * Алгоритмы:
     * - copy_until - Копирует все элементы в начале входного диапазона, которые не удовлетворяют предикату, в выходной диапазон.
     * - copy_while - Копирует все элементы из начала входного диапазона в выходной диапазон, пока выполняется предикат.
     * - copy_if_until - Копирует все элементы, удовлетворяющие предикату элемента, из начала входного диапазона в выходной диапазон,
     * пока не будет выполнен предикат завершения
     * - copy_if_while - Копирует все элементы, удовлетворяющие предикату элемента, из начала входного диапазона в выходной диапазон,
     * пока выполняется предикат завершения
     */
    static auto exampleCopyAlgorithms() -> void;

    /*!
     * \brief Примеры использования других алгоритмов
     * \details
     * Алгоритмы:
     * - none_of_equal - Не соответствует ли ни один из элементов диапазона значению
     * - one_of_equal - Соответствует ли значению только один из элементов диапазона
     * - is_decreasing - Убывает ли вся последовательность; т.е. каждый элемент меньше или равен предыдущему
     * - is_increasing - Возрастает ли вся последовательность; т.е. каждый элемент больше или равен предыдущему
     * - is_strictly_decreasing - Является ли вся последовательность строго убывающей; т.е. каждый элемент меньше предыдущего
     * - is_strictly_increasing - Является ли вся последовательность строго возрастающей; т.е. каждый элемент больше предыдущего
     * - clamp - содержит две функции для «зажатия» значения между парой граничных значений.
     * - clamp_range - выполнить clamp для диапазона
     * - find_not - Алгоритм находит первое значение в заданной последовательности, которое не равно заданному значению.
     * - find_backward - аналог find, за исключением того, что элементы заданной последовательности оцениваются в обратном порядке.
     * - find_not_backward - Найти последний элемент в последовательности, который не равен значению.
     * - find_if_backward - Найти последний элемент в последовательности, удовлетворяющей предикату.
     * - find_if_not - Найти первый элемент в последовательности, не удовлетворяющий предикату.
     * - find_if_not_backward - Найти последний элемент в последовательности, которая не удовлетворяет предикату.
     * - gather - Эта функция принимает последовательность элементов, определенную парой итераторов, и перемещает элементы, удовлетворяющие предикату,
     * в позицию, называемую точкой опоры в последовательности. Алгоритм стабилен, т.е. элементы, возвращающие истину для предиката, будут располагаться
     * в той же последовательности, что и в старой последовательности.
     * - hex - принимает последовательность значений и преобразует их в шестнадцатеричные символы
     * - unhex - обратная функция для hex
     * - hex_lower - Преобразование последовательности целочисленных типов в строчную шестнадцатеричную последовательность символов
     * - is_palindrome - Алгоритм проверяет последовательность и возвращает true, если последовательность является палиндромом; т. е. он идентичен
     * при движении назад или вперед.
     * - is_partitioned_until - Алгоритм проверяет, разделена ли последовательность в соответствии с предикатом; другими словами, все элементы
     * последовательности, удовлетворяющие предикату, находятся в начале последовательности.
     * - apply_reverse_permutation и apply_permutation - Алгоритмы преобразуют последовательность элементов в соответствии с порядком последовательности
     * индексов.
     * - iota_n - Генерирует возрастающую последовательность значений и сохраняет их во входном диапазоне.
     * - power - Возведение значения в целочисленную степень
     */
    static auto exampleOtherAlgorithms() -> void;

};
