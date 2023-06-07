#include "SimpleFunction.h"

namespace NoOpenMP {

auto sum(QVector<int>& vector) -> int
{
    int sum = 0;

    for (int i = 0; i < vector.length(); ++i)
        sum = sum + vector[i];

    return sum;
}

} // namespace NoOpenMP
