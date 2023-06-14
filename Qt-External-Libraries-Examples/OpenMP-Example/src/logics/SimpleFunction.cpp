#include "SimpleFunction.h"

namespace NoOpenMP {

auto sum(QVector<int>& vector) -> int
{
    int sum = 0;

    for (int i = 0; i < vector.length(); ++i)
        sum = sum + vector[i];

    return sum;
}

auto multiply(const QVector<int>& vectorOne, const QVector<int>& vectorTwo) -> QVector<int>
{
    if (vectorOne.length() != vectorTwo.length())
        throw std::bad_array_new_length();

    QVector<int> answer(QVector<int>(vectorOne.length()));

    for (int i = 0; i < vectorOne.length(); ++i)
        answer[i] = vectorOne.at(i) * vectorTwo.at(i);

    return answer;
}

} // namespace NoOpenMP
