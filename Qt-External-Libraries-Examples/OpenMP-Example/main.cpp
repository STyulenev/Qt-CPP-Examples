#include <test.h>
#include "ParallelFunction.h"

#include <QDebug>

auto main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) -> int
{
    qDebug() << OpenMP::checkOpenMP();

    QTest::qExec(new Test, argc, argv);

    return 0;
}
