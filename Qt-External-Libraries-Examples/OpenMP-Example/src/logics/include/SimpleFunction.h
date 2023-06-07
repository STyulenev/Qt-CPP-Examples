#pragma once

#include <QVector>

namespace NoOpenMP {

auto sum(QVector<int>& vector) -> int;

auto multiply(const QVector<int>& vectorOne, const QVector<int>& vectorTwo) -> QVector<int>;

} // namespace NoOpenMP
