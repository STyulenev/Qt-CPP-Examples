#pragma once

/*!
 * \brief The SmartPointers class
 * \details
 * Умные указатели boost:
 * - boost::shared_ptr;
 * - boost::scoped_ptr;
 * - boost::weak_ptr;
 * - boost::intrusive_ptr;
 *
 * Умные указатели stl:
 * - stl::auto_ptr (C++11 deprecated, C++17 removed);
 * - stl::shared_ptr;
 * - stl::scoped_ptr;
 * - stl::weak_ptr;
 *
 * boost::intrusive_ptr - используется при работе с объектами, использующими встроенный счетчик ссылок. Пример – COM-объекты.
 * Этот класс предполагает, что определены функции intrusive_ptr_add_ref и intrusive_ptr_release (не являющиеся фунциями-членами хранимого класса),
 * фактически увеличивающие или уменьшающие счетчик ссылок объекта.
 */
class SmartPointers
{
private:
    SmartPointers() = default;
    ~SmartPointers() = default;

public:
    /*!
     * \brief Пример использования shared_ptr
     * \details
     * shared_ptr предназначен для ситуаций, когда управлять временем существования объекта в памяти требуется нескольким владельцам.
     * После инициализации указателя shared_ptr его можно копировать, передавать по значению в аргументах функций и присваивать другим
     * экземплярам shared_ptr. Все экземпляры указывают на один и тот же объект и имеют общий доступ к одному "блоку управления", который
     * увеличивает и уменьшает счетчик ссылок, когда указатель shared_ptr добавляется, выходит из области действия или сбрасывается.
     * Когда счетчик ссылок достигает нуля, блок управления удаляет ресурс в памяти и самого себя.
     *
     * boost::shared_ptr = std::shared_ptr
     *
     * Заголовочные файлы:
     * #include <boost/smart_ptr/shared_ptr.hpp>
     * #include <boost/make_shared.hpp> - для использования фабричного метода получения элементов.
     *
     * boost::shared_ptr/std::shared_ptr - универсальный инструмент для управления общим владением объектом или массивом;
     * boost::make_shared/std::make_shared - фабричная функция для отказа от new
     */
    static auto SharedPointerExample() -> void;

    /*!
     * \brief Пример использования scoped_ptr
     * \details
     * scoped_ptr отключает копирование и даже конструкцию перемещения. Таким образом, он является единственным владельцем ресурса,
     * и его право собственности не может быть передано. Следовательно, scoped_ptr может жить только внутри области видимости. Или как
     * элемент данных объекта. Как интеллектуальный указатель, он сохраняет преимущество удаления своего базового указателя
     * в своем деструкторе.
     *
     * boost::scoped_ptr ~ std::unique_ptr, только std::unique_ptr может передать владение объектом через std::move(), а boost::scoped_ptr нет.
     * Отсутствует boost::make_scoped(), так как отключено копирование и перемещение.
     *
     * Заголовочные файл - #include <boost/smart_ptr/scoped_ptr.hpp>
     */
    static auto ScopedPointerExample() -> void;

    /*!
     * \brief Пример использования weak_ptr
     * \details
     * Несколько std::weak_ptr могут содержать ссылку на общий объект вместе с другими std::shared_ptr's, но они не увеличивают счетчик ссылок.
     * Это означает, что если объект больше не  std::shared_ptr хранится, этот объект будет удален, даже если некоторые слабые указатели все еще
     * указывают на него. По этой причине слабый указатель должен проверять, жив ли еще объект, на который он указывает:
     * \code
     * if (sp.lock()) {
     *     // the resource is still here and can be used
     * } else {
     *     // the resource is no longer here
     * }
     * \endcode
     *
     * boost::weak_ptr = std::weak_ptr
     *
     * Заголовочные файл - #include <boost/smart_ptr/weak_ptr.hpp>
     */
    static auto WeakPointerExample() -> void;
};
