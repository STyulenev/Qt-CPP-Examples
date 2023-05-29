#pragma once

#include <QDebug>

/*!
 * boost::multi_index - определять контейнеры, поддерживающие произвольное количество интерфейсов. В то время как std::vector предоставляет интерфейс,
 * поддерживающий прямой доступ к элементам с помощью индекса, а std::set предоставляет интерфейс для сортировки элементов, boost::multi_index позволяет
 * определять контейнеры, поддерживающие оба интерфейса. Такой контейнер можно использовать для доступа к элементам с использованием индекса и в
 * отсортированном виде.
*/
namespace BoostMultiIndex {

auto exampleBoostMultiIndex() -> void;

auto exampleBoostMultiIndex2() -> void;

} // namespace BoostMultiIndex
