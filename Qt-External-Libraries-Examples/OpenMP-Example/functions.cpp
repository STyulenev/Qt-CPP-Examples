#include "functions.h"

namespace OpenMP {

auto sum(QVector<int>& vector) -> int
{
    int sum = 0;

#pragma omp parallel for reduction (+:sum)
    for (int i = 0; i < vector.length(); ++i)
        sum = sum + vector[i];

    return sum;
}

} // namespace OpenMP


namespace NoOpenMP {

auto sum(QVector<int>& vector) -> int
{
    int sum = 0;

    for (int i = 0; i < vector.length(); ++i)
        sum = sum + vector[i];

    return sum;
}

} // namespace NoOpenMP
