#include "test.h"

#include <functions.h>

Test::Test(QObject* parent) :
    QObject(parent)
{

}

auto Test::test_bench1() -> void
{
    QBENCHMARK {
        QVector<int> vector;
        for (int i = 0; i < 100000; ++i)
            vector.push_back(i);

        OpenMP::sum(vector);
    }
}

auto Test::test_bench2() -> void
{
    QBENCHMARK {
        QVector<int> vector;
        for (int i = 0; i < 100000; ++i)
            vector.push_back(i);

        NoOpenMP::sum(vector);
    }
}
