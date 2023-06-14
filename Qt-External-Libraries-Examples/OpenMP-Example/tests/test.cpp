#include "test.h"

#include "SimpleFunction.h"
#include "ParallelFunction.h"

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

auto Test::test_bench3() -> void
{
    QBENCHMARK {
        QVector<int> vector1;
        QVector<int> vector2;

        for (int i = 0; i < 100000; ++i) {
            vector1.push_back(i);
            vector2.push_back(i);
        }

        QVector<int> vector3 = OpenMP::multiply(vector1, vector2);

    }
}

auto Test::test_bench4() -> void
{
    QBENCHMARK {
        QVector<int> vector1;
        QVector<int> vector2;

        for (int i = 0; i < 100000; ++i) {
            vector1.push_back(i);
            vector2.push_back(i);
        }

        QVector<int> vector3 = NoOpenMP::multiply(vector1, vector2);
    }
}
