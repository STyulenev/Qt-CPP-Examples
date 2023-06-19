#pragma once

#include <QDebug>

/*!
 * \brief The BoostGeneric class
 * \details
 * Следующие библиотеки поддерживают универсальное программирование:
 * - Boost.TypeTraits предоставляет функции для проверки свойств типов.
 * - Boost.EnableIf можно использовать вместе с Boost.TypeTraits, например, для перегрузки функций на основе возвращаемых ими типов.
 * - Boost.Fusion позволяет создавать гетерогенные контейнеры — контейнеры, элементы которых могут иметь разные типы.
 *
 */
class BoostGeneric
{
private:
    BoostGeneric() = default;
    ~BoostGeneric() = default;

public:
    /*!
     * \brief Пример проверки типов/методов/операторов для универсального программирования
     * \details
     * Заголовочный файл - #include <boost/type_traits.hpp>
     *
     * Функции проверок:
     * - boost::is_integral проверяет, является ли тип целочисленным — может ли он хранить целые числа
     * - boost::is_floating_point проверяет, хранит ли тип числа с плавающей запятой
     * - boost::is_arithmetic проверяет, поддерживает ли тип арифметические операторы
     * - boost::is_reference можно использовать для определения того, является ли тип ссылкой
     * - boost::has_plus - возможна ли операция +
     * - boost::has_pre_increment - возможна ли операция ++value
     * - boost::has_trivial_copy - возможно ли скопировать
     * - boost::has_virtual_destructor<int> - есть ли виртуальный деструктор
     *
     * Полный список функций для проверок:
     * - add_const
     * - add_cv
     * - add_lvalue_reference
     * - add_pointer
     * - add_reference
     * - add_rvalue_reference
     * - add_volatile
     * - aligned_storage
     * - alignment_of
     * - conditional
     * - conjunction
     * - common_type
     * - copy_cv
     * - copy_cv_ref
     * - copy_reference_
     * - decay
     * - declval
     * - detected
     * - detected_or
     * - disjunction
     * - enable_if_
     * - extent
     * - floating_point_promotion
     * - function_traits
     * - has_bit_and
     * - has_bit_and_assign
     * - has_bit_or
     * - has_bit_or_assign
     * - has_bit_xor
     * - has_bit_xor_assign
     * - has_complement
     * - has_dereference
     * - has_divides
     * - has_divides_assign
     * - has_equal_to
     * - has_greater
     * - has_greater_equal
     * - has_left_shift
     * - has_left_shift_assign
     * - has_less
     * - has_less_equal
     * - has_logical_and
     * - has_logical_not
     * - has_logical_or
     * - has_minus
     * - has_minus_assign
     * - has_modulus
     * - has_modulus_assign
     * - has_multiplies
     * - has_multiplies_assign
     * - has_negate
     * - has_new_operator
     * - has_not_equal_to
     * - has_nothrow_assign
     * - has_nothrow_constructor
     * - has_nothrow_copy
     * - has_nothrow_destructor
     * - has_nothrow_copy_constructor
     * - has_nothrow_default_constructor
     * - has_plus
     * - has_plus_assign
     * - has_post_decrement
     * - has_post_increment
     * - has_pre_decrement
     * - has_pre_increment
     * - has_right_shift
     * - has_right_shift_assign
     * - has_trivial_assign
     * - has_trivial_constructor
     * - has_trivial_copy
     * - has_trivial_copy_constructor
     * - has_trivial_default_constructor
     * - has_trivial_destructor
     * - has_trivial_move_assign
     * - has_trivial_move_constructor
     * - has_unary_minus
     * - has_unary_plus
     * - has_virtual_destructor
     * - integral_constant
     * - integral_promotion
     * - is_abstract
     * - is_arithmetic
     * - is_array
     * - is_assignable
     * - is_base_of
     * - is_bounded_array
     * - is_class
     * - is_complete
     * - is_complex
     * - is_compound
     * - is_const
     * - is_constructible
     * - is_convertible
     * - is_copy_assignable
     * - is_copy_constructible
     * - is_default_constructible
     * - is_destructible
     * - is_detected
     * - is_detected_convertible
     * - is_detected_exact
     * - is_empty
     * - is_enum
     * - is_final
     * - is_floating_point
     * - is_function
     * - is_fundamental
     * - is_integral
     * - is_list_constructible
     * - is_lvalue_reference
     * - is_member_function_pointer
     * - is_member_object_pointer
     * - is_member_pointer
     * - is_nothrow_move_assignable
     * - is_nothrow_move_constructible
     * - is_nothrow_swappable
     * - is_object
     * - is_pod
     * - is_pointer
     * - is_polymorphic
     * - is_reference
     * - is_rvalue_reference
     * - is_same
     * - is_scalar
     * - is_scoped_enum
     * - is_signed
     * - is_stateless
     * - is_swappable
     * - is_trivially_copyable
     * - is_unbounded_array
     * - is_union
     * - is_unscoped_enum
     * - is_unsigned
     * - is_virtual_base_of
     * - is_void
     * - is_volatile
     * - make_signed
     * - make_unsigned
     * - make_void
     * - negation
     * - nonesuch
     * - promote
     * - rank
     * - remove_all_extents
     * - remove_const
     * - remove_cv
     * - remove_cv_ref
     * - remove_extent
     * - remove_pointer
     * - remove_reference
     * - remove_volatile
     * - type_identity
     * - type_with_alignment
     */
    static auto exampleBoostTypeTraits() -> void;

    /*!
     * \brief Пример использования enable_if
     * \details
     * Заголовочный файл - #include <boost/utility/enable_if.hpp>
     *
     * boost::enable_if позволяет вставлять условия type_traits в шаблонные функции
     */
    static auto exampleBoostEnableIf() -> void;

    /*!
     * \brief Пример использования Boost.Fusion
     * \details
     * Boost.Fusion помогает при работе с контейнерами в шаблонных функциях
     *
     * Стандартная библиотека предоставляет множество контейнеров, которые имеют одну общую черту: они однородны. То есть контейнеры из
     * стандартной библиотеки могут хранить элементы только одного типа. Вектор типа std::vector<int> может хранить только значения int,
     * а вектор типа std::vector<std::string> может хранить только строки.
     * Boost.Fusion позволяет создавать гетерогенные контейнеры. Например, можно создать вектор, первым элементом которого является целое число,
     * а вторым элементом — строка. Кроме того, Boost.Fusion предоставляет алгоритмы для обработки гетерогенных контейнеров.
     * Boost.Fusion - стандартная библиотека для гетерогенных контейнеров.
     *
     * Библиотека называется Boost.Fusion, потому что она объединяет два мира: программы на C++ обрабатывают значения во время выполнения
     * и типы во время компиляции.
     *
     * Итераторы Fusion:
     * - boost::fusion::end()
     * - boost::fusion::distance()
     * - boost::fusion::next()
     * - boost::fusion::prior().
     */
    static auto exampleBoostFusion() -> void;

};

