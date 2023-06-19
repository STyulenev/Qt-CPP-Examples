#pragma once

/*!
 * \brief Пример использования контейнеров указателей Pointer Container
 * \details
 * Удобные контейнеры умных указателей для управления объектами, размещенными в куче, которые не требуют подсчета ссылок на содержащиеся объекты.
 * boost::ptr_vector<T>, в отличие от boost::vector<boost::shared_ptr<int>> не считает ссылки, а является аналогом std::vector<std::unique_ptr<T>>
 * То есть, PointerContainer обеспечивают поведение, аналогичное стандартным контейнерам, но поддерживают объекты, размещенные в куче.
 *
 * Разница:
 * - права собственности на элементы в контейнере указателей НЕ являются общими
 * - если явно не указано в типе, контейнер указателя не будет содержать нулевого указателя
 * - контейнер указателя имеет семантику глубокого копирования (с использованием new_clone метода) и может быть скопирован, только если хранящийся объект поддается копированию
 * - контейнер-указатель имеет глубокую семантику const, то есть, если контейнер является const, то невозможно изменить один из его элементов.
 *
 * Последовательные:
 * - ptr_array  (#include <boost/ptr_container/ptr_array.hpp>)
 * - ptr_vector (#include <boost/ptr_container/ptr_vector.hpp>)
 * - ptr_list   (#include <boost/ptr_container/ptr_list.hpp>)
 * - ptr_deque  (#include <boost/ptr_container/ptr_deque.hpp>)
 *
 * Ассоциативные:
 * - ptr_set           (#include <boost/ptr_container/ptr_set.hpp>)
 * - ptr_unordered_set (#include <boost/ptr_container/ptr_unordered_set.hpp>)
 * - ptr_map           (#include <boost/ptr_container/ptr_map.hpp>)
 * - ptr_unordered_map (#include <boost/ptr_container/ptr_unordered_map.hpp>)
 *
 */
class PointerContainer
{
private:
    PointerContainer() = default;
    ~PointerContainer() = default;

public:
    /*!
     * \brief Пример использования boost::ptr_vector
     * \details
     * boost::ptr_vector<T> != std::vector<std::shared_ptr<T>> or boost::list<std::shared_ptr<T>>
     * boost::ptr_vector<T> = std::vector<std::unique_ptr<T>>
     * Заголовочный файл - #include <boost/ptr_container/ptr_vector.hpp>
     */
    static auto PointerVectorExample() -> void;

    /*!
     * \brief Пример использования boost::ptr_list
     * \details
     * boost::ptr_list<T> != std::list<std::shared_ptr<T>> or boost::list<std::shared_ptr<T>>
     * boost::ptr_list<T> = std::list<std::unique_ptr<T>>
     * Заголовочный файл - #include <boost/ptr_container/ptr_list.hpp>
     */
    static auto PointerListExample() -> void;

};

