#pragma once

#include <QDebug>

#include <boost/container/vector.hpp>

// SearchingAlgorithms
#include <boost/algorithm/searching/boyer_moore.hpp>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>

// C++11 Algorithms
#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <boost/algorithm/cxx11/none_of.hpp>
#include <boost/algorithm/cxx11/one_of.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/cxx11/is_partitioned.hpp>
#include <boost/algorithm/cxx11/is_permutation.hpp>
#include <boost/algorithm/cxx11/partition_point.hpp>
#include <boost/algorithm/cxx11/partition_copy.hpp>
#include <boost/algorithm/cxx11/copy_if.hpp>
#include <boost/algorithm/cxx11/copy_n.hpp>
#include <boost/algorithm/cxx11/iota.hpp>

//#include <boost/algorithm/string.hpp>

namespace BoostAlgorithmsExamples {

/*!
 * \brief Примеры алгоритмов поиска подстроки в строке
 * \details
 * 1. Алгоритм Бойера-Мура
 * 2. Алгоритм Бойера-Мура-Хорспула
 * 3. Алгоритм Кнута-Морриса-Пратта
 */
auto ExampleSearchingAlgorithms() -> void;

/*!
 * \brief ExampleCPP11Algorithms
 * 1. all_of - Алгоритм возвращает true, если все они имеют общее свойство.
 * 2. any_of - Алгоритм возвращает true, если какой-либо из элементов обладает определенным свойством.
 * 3. one_of - Алгоритм возвращает значение true, если ровно один из элементов последовательности обладает определенным свойством.
 * 4. none_of - Алгоритм возвращает true, если ни один из них не имеет общего свойства.
 * 5. is_sorted - Функция определяет, полностью ли отсортирована последовательность по заданным критериям.
 * 6. is_partitioned - Алгоритм возвращает true, если все элементы последовательности, удовлетворяющие предикату, находятся в начале последовательности.
 * 7. is_permutation - Алгоритм проверяет, является ли одна последовательность перестановкой второй.
 * 8. partition_point - Алгоритм возвращает итератор, который «указывает» на первый элемент в последовательности не удовлетворяющий предикату.
 * 9. partition_copy - Алгоритм копирует подмножество последовательности в две новые последовательности в зависимости от результата предиката.
 * 10. copy_if - Алгоритм копирует подмножество в зависимости от условия.
 * 11. copy_n - Алгоритм копирует подмножество из n элементов.
 * 12. iota - Алгоритм генерирует возрастающую последовательность.
 */
auto ExampleCPP11Algorithms() -> void;

} // namespace BoostAlgorithmsExamples

