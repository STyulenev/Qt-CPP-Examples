#pragma once

#include <QDebug>

/*!
 * \brief Пример использования библиотеки Boost.String
 * \details
 * Следующие библиотеки предоставляют инструменты для упрощения работы со строками:
 * - Boost.StringAlgorithms определяет множество алгоритмов специально для строк.
 * - Boost.LexicalCast предоставляет оператор приведения для преобразования числа в строку или наоборот.
 * - Boost.Format предоставляет типобезопасную альтернативу std::printf(). Как и Boost.LexicalCast, эта библиотека использует внутренние потоки строк.
 * - Boost.Regex и Boost.Xpressive — это библиотеки для поиска в строках с использованием регулярных выражений.
 * - Boost.Tokenizer позволяет перебирать подстроки в строке.
 * - Boost.Spirit можно использовать для разработки парсеров на основе правил, аналогичных расширенной форме Бэкуса-Наура.
 *
 */
class BoostString
{
private:
    BoostString() = default;
    ~BoostString() = default;

public:
    /*!
     * \brief Пример использования алгоритмов для строк
     * \details
     * Заголовочный файл - #include <boost/algorithm/string.hpp>
     *
     * Алгоритмы Case Conversion:
     * - to_upper() - string -> STRING
     * - to_lower() - STRING -> string
     * - to_upper_copy() - тоже самое что и to_upper(), только возвращает переобразованную копию
     * - to_lower_copy() - тоже самое что и to_lower(), только возвращает переобразованную копию
     *
     * Алгоритмы Trimming:
     * - trim_left_copy_if() - - trim_left() + предикат на проверку удаляемого символа + вывод в новую строку преобразованной копии
     * - trim_left_if() - trim_left() + предикат на проверку удаляемого символа
     * - trim_left_copy() - trim_left() + возврат преобразованной копии
     * - trim_left() - обрезка пробелов слева
     * - trim_right_copy_if() - trim_left_copy_if() аналог справа
     * - trim_right_if() - trim_left_if() аналог справа
     * - trim_right_copy() - trim_left_copy() аналог справа
     * - trim_right() - обрезка пробелов справа
     * - trim_copy_if() - trim() + предикат на проверку удаляемого символа + вывод в новую строку преобразованной копии
     * - trim_if() - trim() + предикат на проверку удаляемого символа
     * - trim_copy() - trim() + вывод копии
     * - trim() - обрезка пробелов слева и справа
     *
     * Алгоритмы Predicates:
     * - starts_with() - Эта функция используется для проверки того, совпадает ли начало данной строки с заданным шаблоном.
     * - istarts_with() - тоже самое starts_with() но игнорирует регистр
     * - ends_with() - Эта функция используется для проверки того, совпадает ли конец данной строки с заданным шаблоном.
     * - iends_with() - тоже самое ends_with() но игнорирует регистр
     * - contains() - Эта функция используется для проверки того, есть ли подстрока в данной строки.
     * - icontains() - тоже самое contains() но игнорирует регистр
     * - equals() - сравнивает две строки
     * - iequals() - тоже самое equals() но игнорирует регистр
     * - lexicographical_compare() - сравнивает две строки лексикографически (то есть, есть ли все символы из первой строки во второй)
     * - ilexicographical_compare()  - тоже самое lexicographical_compare() но игнорирует регистр
     * - all() - проверить поэлементно строку в предикате
     *
     * Алгоритмы Find algorithms:
     * - find_first() - алгоритм ищет вхождение подстроки в строку и возвращает интератор на начало вхождения
     * - ifind_first() - тоже самое find_first() но игнорирует регистр
     * - find_last() - алгоритм ищет вхождение подстроки в строку и возвращает интератор на конец вхождения
     * - ifind_last() - тоже самое find_last() но игнорирует регистр
     * - find_nth() - ищет N вхождение подстроки в строку
     * - ifind_nth() - тоже самое find_nth() но игнорирует регистр
     * - find_head() - получить итератор на начала строки со сдвигом
     * - find_tail() - получить итератор на конец строки со сдвигом
     * - find_token() - возвращает строку пока совпадает предикат
     * - find_regex() - ищет подстроку по рег выражению
     * - find()
     *
     * Алгоритмы Erase/Replace:
     * (replace - замена, erase - удаление, i - регистронезависимость, copy - возврат копии, first - сначала поиск,
     * last - с конца поиск, nth - подстрока, all - все вхождения, head - подстрока в начале, tail - подстрока в конце,
     * regex - подстрока по рег выражению, format - форматирование)
     * - replace_first()
     * - replace_first_copy()
     * - ireplace_first()
     * - ireplace_first_copy()
     * - erase_first()
     * - erase_first_copy()
     * - ierase_first()
     * - ierase_first_copy()
     * - replace_last()
     * - replace_last_copy()
     * - ireplace_last()
     * - ireplace_last_copy()
     * - erase_last()
     * - erase_last_copy()
     * - ierase_last()
     * - ierase_last_copy()
     * - replace_nth()
     * - replace_nth_copy()
     * - ireplace_nth()
     * - ireplace_nth_copy()
     * - erase_nth()
     * - erase_nth_copy()
     * - ierase_nth()
     * - ierase_nth_copy()
     * - replace_all()
     * - replace_all_copy()
     * - ireplace_all()
     * - ireplace_all_copy()
     * - erase_all()
     * - erase_all_copy()
     * - ierase_all()
     * - ierase_all_copy()
     * - replace_head()
     * - replace_head_copy()
     * - erase_head()
     * - erase_head_copy()
     * - replace_tail()
     * - replace_tail_copy()
     * - erase_tail()
     * - erase_tail_copy()
     * - replace_regex()
     * - replace_regex_copy()
     * - erase_regex()
     * - erase_regex_copy()
     * - replace_all_regex()
     * - replace_all_regex_copy()
     * - erase_all_regex()
     * - erase_all_regex_copy()
     * - find_format()
     * - find_format_copy()
     * - find_format_all()
     * - find_format_all_copy()()
     *
     * Алгоритмы Split:
     * - find_all() - найти все подстроки и скопировать в вектор
     * - ifind_all() - тоже что и find_all() только регистронезависимый
     * - find_all_regex() - тоже что и find_all() только рег выр
     * - split() - разделить по символу
     * - split_regex() - разделить по рег выр
     * - iter_find()
     * - iter_split()
     *
     * Алгоритмы Join:
     * - join - соединить с разделителем
     * - join_if() - соединить с разделителем + условие
     *
     * Алгоритмы Finders: (поиск с возвратом true/false)
     * - first_finder()
     * - last_finder()
     * - nth_finder()
     * - head_finder()
     * - tail_finder()
     * - token_finder()
     * - range_finder()
     * - regex_finder()
     *
     * Алгоритмы Find Iterators:
     * - find_iterator()
     * - split_iterator()
     *
     * Алгоритмы Predicates: (готовые функции для проверки)
     * - is_classified()
     * - is_space()
     * - is_alnum()
     * - is_alpha()
     * - is_cntrl()
     * - is_digit()
     * - is_graph()
     * - is_lower()
     * - is_print()
     * - is_punct()
     * - is_upper()
     * - is_xdigit()
     * - is_any_of()
     * - is_from_range()
     */
    static auto exampleBoostStringAlgorithms() -> void;


    /*!
     * \brief Пример использования приведение типов из строк
     * \details
     * Заголовочный файл - #include <boost/lexical_cast.hpp>
     */
    static auto exampleBoostStringLexicalCast() -> void;

    /*!
     * \brief Пример использования форматирования для строк
     * \details
     * Заголовочный файл - #include <boost/format.hpp>
     *
     * Boost.Format предлагает замену функции std::printf(). std::printf() исходит из стандарта C и позволяет выводить форматированные данные.
     * Однако он не является ни типобезопасным, ни расширяемым. Boost.Format предоставляет типобезопасную и расширяемую альтернативу.
     *
     * Алгоритмы Formatters: (форматирование строк)
     * - const_formatter()
     * - identity_formatter()
     * - empty_formatter()
     * - regex_formatter()
     */
    static auto exampleBoostStringFormat() -> void;

    /*!
     * \brief Пример использования рег выражений для строк
     * \details
     * Заголовочный файл - #include <boost/regex.hpp>
     */
    static auto exampleBoostStringRegex() -> void;


};
