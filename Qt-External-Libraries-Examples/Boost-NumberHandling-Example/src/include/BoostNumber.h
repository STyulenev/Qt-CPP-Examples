#pragma once

#include <QDebug>

/*!
 * \brief Пример использования библиотеки Boost.Number
 * \details
 * Следующие библиотеки предоставляют инструменты для упрощения работы с числами:
 * - Boost.Integer - предоставляет целочисленные типы, чтобы, например, указать точное количество байтов, используемых переменной.
 * - Boost.Accumulators - предоставляет функии суммирования для вычисления среднего числа, среднего отклонения и т.д.
 * - Boost.MinMax - позволяет получить наименьшее и наибольшее число в контейнере одним вызовом функции.
 * - Boost.Random - предоставляет генераторы случайных чисел.
 * - Boost.NumericConversion - предоставляет оператор приведения, который защищает от непреднамеренного переполнения.
 */
class BoostNumber
{
private:
    BoostNumber() = default;
    ~BoostNumber() = default;

public:
    /*!
     * \brief Пример дополнительных чисел Integer
     * \details
     * Заголовочный файл - #include <boost/cstdint.hpp>
     *
     * Точный размер:
     * - int8_t
     * - int16_t
     * - int32_t
     * - int64_t
     * - uint8_t
     * - uint16_t
     * - uint32_t
     * - uint64_t
     *
     * Не меньше чем:
     * - int_least8_t
     * - int_least16_t
     * - int_least32_t
     * - int_least64_t
     * - uint_least8_t
     * - uint_least16_t
     * - uint_least32_t
     * - uint_least64_t
     *
     * Наилучший размер для производительности:
     * - int_fast8_t
     * - int_fast16_t
     * - int_fast32_t
     * - int_fast64_t
     * - uint_fast8_t
     * - uint_fast16_t
     * - uint_fast32_t
     * - uint_fast64_t
     *
     * ...64_t доступно не везде
     */
    static auto exampleBoostInteger() -> void;


};
