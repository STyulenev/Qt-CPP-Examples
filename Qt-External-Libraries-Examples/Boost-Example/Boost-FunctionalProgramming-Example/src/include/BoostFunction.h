#pragma once

#include <QDebug>

/*!
 * \brief Пример использования функциональных объектов
 * \details
 * boost::function и std::function полностью эквивалентны
 *
 * Библиотека функций Boost.Function содержит семейство шаблонов классов, которые являются оболочками объектов функций. Понятие похоже на обобщенный
 * обратный вызов. Он разделяет функции с указателями функций в том, что оба определяют интерфейс вызова, через который может быть вызвана
 * некоторая реализация, и реализация, которая вызываемый объект может меняться в ходе выполнения программы. Это на самом деле помогает играть
 * с функциями, так как до сих пор мы просто реализовывали логику с переменными, а теперь мы собираемся реализовать ее с помощью функций.
 */
class BoostFunction
{

private:
    BoostFunction() = default;
    ~BoostFunction() = default;

public:
    /*!
     * \brief Пример использования функциональных объектов
     * \details
     * Заголовочный файл - #include <boost/function.hpp>
     */
    static auto exampleBoostFunction() -> void;

    /*!
     * \brief Пример передачи объекта и метода в функциональный объект
     */
    static auto exampleBoostFunctionBinding() -> void;
};
