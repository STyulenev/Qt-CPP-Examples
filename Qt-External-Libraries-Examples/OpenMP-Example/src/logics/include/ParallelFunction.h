#pragma once

#include <QVector>

namespace OpenMP {

auto checkOpenMP() -> QString;

auto sum(QVector<int>& vector) -> int;

} // namespace OpenMP
