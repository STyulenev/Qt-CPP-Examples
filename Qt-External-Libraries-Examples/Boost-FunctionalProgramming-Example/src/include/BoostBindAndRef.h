#pragma once

#include <QDebug>

/*!
 * \brief Boost.Bind и Boost.Ref
 * \details
 * boost::bind — это обобщение стандартных функций std::bind1st и std::bind2nd. Он поддерживает произвольные функции, объекты функций,
 * указатели функций и функции-члены. Boost::bind привязывает любой аргумент к определенному значению или направляет входные аргументы в
 * произвольные позиции, а также привязывает параметры к функциям. Он принимает вызываемый объект и возвращает вызываемый объект, который
 * не указан, поэтому он обычно используется с ключевым словом auto.
 *
 * boost::ref используется для передачи ссылок на шаблон функции, который обычно берет копии своего аргумента. В прошлом он изначально был
 * частью библиотеки кортежей. Обычно мы можем передавать по значению, но это подходит для такой ситуации, когда они делают не данные или у
 * них очень мало параметров. Но в некоторых случаях вы можете содержать большой объем данных с вашей системной функцией, и передача их со
 * значением нежелательна
 */
class BoostBindAndRef
{
private:
    BoostBindAndRef() = default;
    ~BoostBindAndRef() = default;

public:
    /*!
     * \brief Пример использования биндинга функций
     * \details
     * Заголовочный файл - #include <boost/bind.hpp>
     *
     */
    static auto exampleBoostBind() -> void;

    /*!
     * \brief Пример использования типов биндинга функций
     * \details
     * Заголовочный файл - #include <boost/functional.hpp>
     *
     * Function object traits:
     * - unary_traits
     * - binary_traits
     *
     * Negators:
     * - unary_negate
     * - binary_negate
     * - not1
     * - not2
     *
     * Binders:
     * - binder1st
     * - binder2nd
     * - bind1st
     * - bind2nd
     *
     * Adapters for pointers to functions:
     * - pointer_to_unary_function
     * - pointer_to_binary_function
     * - ptr_fun
     *
     * Adapters for pointers to member functions:
     * - mem_fun_t
     * - mem_fun1_t
     * - const_mem_fun_t
     * - const_mem_fun1_t
     * - mem_fun_ref_t
     * - mem_fun1_ref_t
     * - const_mem_fun_ref_t
     * - const_mem_fun1_ref_t
     * - mem_fun
     * - mem_fun_ref
     */
    static auto exampleBoostBindFunctions() -> void;

    /*!
     * \brief exampleBoostRef
     * \details
     * Заголовочный файл - #include <boost/ref.hpp>
     *
     * - boost::ref - позволяет передавать по ссылке
     * - boost::cref - позволяет передавать ссылку на константу.
     */
    static auto exampleBoostRef() -> void;
};
