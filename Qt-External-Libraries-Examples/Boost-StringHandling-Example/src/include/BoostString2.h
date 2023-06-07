#pragma once

#include <QDebug>

class BoostString2
{
private:
    BoostString2() = default;
    ~BoostString2() = default;

public:
    /*!
     * \brief Пример использования Xpressive
     * \details
     * Заголовочный файл - #include <boost/xpressive/xpressive.hpp>
     *
     * Boost.Xpressive предоставляет функции для поиска строк с использованием регулярных выражений. Однако Boost.Xpressive позволяет записывать
     * регулярные выражения в виде кода C++, а не строк. Это позволяет во время компиляции проверять, является ли регулярное выражение допустимым
     * или нет.
     */
    static auto exampleBoostXpressive() -> void;

    /*!
     * \brief Пример использования Tokenizer
     * \details
     * Заголовочный файл - #include <boost/tokenizer.hpp>
     *
     * Boost.Tokenizer позволяет перебирать подстроки в строке.
     */
    static auto exampleBoostTokenizer() -> void;
};
