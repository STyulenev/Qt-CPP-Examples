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

#pragma omp parallel for reduction (+:sum) //num_threads(16)
    for (int i = 0; i < vector.length(); ++i) {
        sum = sum + vector[i];
    }

    return sum;
}

auto multiply(const QVector<int>& vectorOne, const QVector<int>& vectorTwo) -> QVector<int>
{
    if (vectorOne.length() != vectorTwo.length())
        throw std::bad_array_new_length();

    QVector<int> answer(QVector<int>(vectorOne.length()));

#pragma omp parallel for //num_threads(16)
    for (int i = 0; i < vectorOne.length(); ++i) {
        answer[i] = vectorOne.at(i) * vectorTwo.at(i);
    }

    return answer;
}

} // namespace OpenMP
