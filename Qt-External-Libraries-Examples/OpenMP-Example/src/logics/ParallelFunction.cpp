#include "ParallelFunction.h"

#include <omp.h>

namespace OpenMP {

auto checkOpenMP() -> QString
{
#if defined(_OPENMP)
    return QString("OpenMP started. Core: %1 Max cores: %2").arg(omp_get_num_threads()).arg(omp_get_max_threads());
#else
    return QString("There is not OpenMP");
#endif
}

auto sum(QVector<int>& vector) -> int
{
    int sum = 0;

#pragma omp parallel for reduction (+:sum)
    for (int i = 0; i < vector.length(); ++i)
        sum = sum + vector[i];

    return sum;
}

} // namespace OpenMP
