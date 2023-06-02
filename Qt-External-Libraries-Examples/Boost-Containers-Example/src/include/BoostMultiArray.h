#pragma once

#include <QDebug>

/*!
 * \brief Пример использования библиотеки Boost.MultiArray (многомерные массивы)
 * \details
 * Boost.MultiArray — это библиотека, упрощающая использование многомерных массивов. Самым важным преимуществом является то,
 * что многомерные массивы можно использовать как контейнеры из стандартной библиотеки (с итераторами, а не указателями).
 * Boost MultiArray — это более эффективный и удобный способ выражения N-мерных массивов, чем существующие альтернативы
 * (особенно формулировку std::vector<std::vector<...>> для N-мерных массивов).
 */
class BoostMultiArray
{
private:
    BoostMultiArray() = default;
    ~BoostMultiArray() = default;

public:
    /*!
     * \brief Пример использования boost::multi_array
     * \details
     * Заголовочный файл - #include <boost/multi_array.hpp>
     *
     * boost::multi_array — это шаблон, ожидающий двух параметров: первый параметр — это тип элементов, которые будут храниться в массиве.
     * Второй параметр определяет, сколько измерений должен иметь массив.
     */
    static auto exampleBoostIMultiArray() -> void;

};
