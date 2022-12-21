#pragma once

#include <QVector>

#include <omp.h>

namespace OpenMP {

auto sum(QVector<int>& vector) -> int;

} // namespace OpenMP

namespace NoOpenMP {

auto sum(QVector<int>& vector) -> int;

} // namespace NoOpenMP
