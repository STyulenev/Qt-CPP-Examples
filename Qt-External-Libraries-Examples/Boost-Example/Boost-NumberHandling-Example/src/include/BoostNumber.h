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

    /*!
     * \brief Пример использования Boost.Accumulators
     * \details
     * Заголовочный файл - #include <boost/accumulators/accumulators.hpp>
     *
     * Некоторые функции для вычисления над числами:
     * - count - количество
     * - covariance - оценка ковариации методом Монте-Карло
     * - density - плостность
     * - error_of<mean> - ошибка среднего
     * - max - максимальное
     * - mean - вычисляет среднее значение выборок, весов или вариаций
     * - median - медиана
     * - min - минимальное
     * - moment - вычисляет n-ый момент
     * и другие ....
     */
    static auto exampleBoostAccumulators() -> void;

    /*!
     * \brief Пример использования Boost.MinMax
     * \details
     * Заголовочный файл - #include <boost/algorithm/minmax.hpp>
     *
     * Предоставляет алгоритм для нахождения минимума и максимума двух значений с использованием только одного вызова функции, который более
     * эффективен, чем вызов std::min() и std::max().
     *
     * boost::minmax() вычисляет минимум и максимум двух объектов. Хотя и std::min(), и std::max() возвращают только одно значение, boost::minmax()
     * возвращает два значения в виде кортежа.
     */
    static auto exampleBoostMinMax() -> void;

    /*!
     * \brief Пример использования Boost.Random
     * \details
     * Заголовочный файл - #include <boost/random.hpp>
     *
     * Boost.Random предоставляет множество генераторов случайных чисел, которые позволяют генерировать случайные числа. В C++ всегда можно было
     * генерировать случайные числа с помощью std::rand() из cstdlib. Однако при использовании std::rand() способ генерации случайных чисел зависит
     * от того, как была реализована стандартная библиотека.
     *
     * Генераторы:
     * minstd_rand0
     * minstd_rand
     * rand48
     * ecuyer1988
     * knuth_b
     * kreutzer1986
     * taus88
     * hellekalek1995
     * mt11213b
     * mt19937
     * mt19937_64
     * __mixmax
     * lagged_fibonacci607
     * lagged_fibonacci1279
     * lagged_fibonacci2281
     * lagged_fibonacci3217
     * lagged_fibonacci4423
     * lagged_fibonacci9689
     * lagged_fibonacci19937
     * lagged_fibonacci23209
     * lagged_fibonacci44497
     * ranlux3
     * ranlux4
     * ranlux64_3
     * ranlux64_4
     * ranlux3_01
     * ranlux4_01
     * ranlux64_3_01
     * ranlux64_4_01
     * ranlux24
     * ranlux48
     */
    static auto exampleBoostRandom() -> void;

    /*!
     * \brief Пример использования Boost.NumericConversion
     * \details
     * Заголовочный файл - #include
     *
     * Boost.NumericConversion используется для преобразования чисел одного числового типа в другой числовой тип.
     *
     * boost::numeric::converter<> - конвертер
     *
     * boost::numeric::bounds<> предоставляет согласованный интерфейс для получения максимального конечного значения, минимального конечного
     * значения и минимального положительного нормализованного значения (0 для целочисленных типов) для числовых типов. Выбор реализации выполняется
     * во время компиляции, поэтому накладные расходы во время выполнения отсутствуют.
     *
     * boost::numeric::numeric_cast придерживается правил неявных преобразований, предусмотренных стандартом C++, таких как усечение типов с плавающей
     * запятой при преобразовании в целочисленные типы. Реализация должна гарантировать, что для преобразования в тип, который может содержать все
     * возможные значения исходного типа, не будет накладных расходов во время выполнения.
     */
    static auto exampleBoostNumericConversion() -> void;
};
