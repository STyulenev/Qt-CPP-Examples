#pragma once

/*!
 * \brief Примеры использования структур данных
 *
 * Структуры:
 * - boost::any — может содержать значение любого типа без указания типа (необходимо проверять перед получением);
 * - boost::optional<T> — может содержать значение типа T или не содержать значения (boost::none);
 * - boost::variant<T, S, ...> — может содержать любой тип из списка T, S, ..., иначе ошибка во время компиляции;
 * - boost::tuple<T, S, ...> - (кортеж) коллекция элементов с фиксированным размером. Любая связанная пара, тройка, четверка и т.д
 * элементов является кортежем. В качестве элементов кортежа могут выступать переменные произвольного типа.
 * - boost::compressed_pair<T, S> — это кортеж из двух элементов, не требующий дополнительной памяти для одного типа, который имеет только размер 1,
 * потому что размер 0 запрещен в std::pair<T, S>.
 * - boost::logic::tribool - аналог bool, однако bool может различать два состояния, а tribool различает и обрабатывает три состояния.
 * - boost::propetry_tree::ptree - это обычная древовидная структура, каждый элемент которой, помимо данных, может содержать упорядоченный список
 * дочерних элементов, каждый из которых имеет свое имя.
 * - boost::dynamic_bitset - класса, используемый для манипуляций с битами. Класс dynamic_bitset используется для представления набора битов в форме 0 (сброс)
 * или 1 (установка). Количество битов для std::bitset должно быть указано во время компиляции, тогда как количество битов для boost::dynamic_bitset
 * указывается во время выполнения.
 */
class DataStructuresExample
{
private:
    DataStructuresExample() = default;
    ~DataStructuresExample() = default;

public:
    /*!
    * \brief Пример использования boost::optional<T>
    * \details
    * boost::optional<T> ~ std::optional<T>
    *
    * Заголовочный файл - #include <boost/optional.hpp> (std - #include <optional>)
    */
    static auto OptionalExample() -> void;

    /*!
    * \brief Пример использования boost::any
    * \details
    * boost::any ~ std::any
    *
    * Принципиальное отличие состоит в том, что boost::any в настоящее время реализация не реализует оптимизацию малых объектов,
    * в то время как std::any реализации могут ее обеспечивать.
    *
    * Заголовочный файл - #include <boost/any.hpp> (std - #include <any>)
    */
    static auto AnyExample() -> void;

    /*!
    * \brief Пример использования boost::variant
    * \details
    * boost::variant<T, S, ...> ~ std::variant<T, S, ...>
    *
    * Заголовочный файл - #include <boost/variant.hpp> (std - #include <variant>)
    */
    static auto VariantExample() -> void;

    /*!
    * \brief Пример использования boost::tuple
    * \details
    * boost::tuple<T, S, ...> ~ std::tuple<T, S, ...>
    *
    * Заголовочный файл - #include <boost/tuple/tuple.hpp> (std - #include <tuple>)
    */
    static auto TupleExample() -> void;

    /*!
     * \brief Пример использования boost::compressed_pair
     * \details
     * boost::compressed_pair<T, S> ~ std::pair<T, S>
     *
     * Заголовочный файл - #include<boost/compressed_pair.hpp>
     */
    static auto CompressedPairExample() -> void;

    /*!
     * \brief Пример использования boost::logic::tribool
     * \details
     * Заголовочный файл - #include <boost/logic/tribool.hpp>
     */
    static auto TriboolPairExample() -> void;

    /*!
     * \brief Пример использования boost::property_tree::ptree
     * \details
     * Заголовочный файл - #include <boost/property_tree/ptree.hpp>
     */
    static auto PropertyTreeExample() -> void;

    /*!
     * \brief Пример использования boost::dynamic_bitset
     * \details
     * boost::dynamic_bitset ~ std::bitset
     *
     * Заголовочный файл - #include <boost/dynamic_bitset.hpp>
     */
    static auto DynamicBitsetExample() -> void;
};

