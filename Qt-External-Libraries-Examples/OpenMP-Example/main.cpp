#include <test.h>

auto main(int argc, char* argv[]) -> int
{
    QTest::qExec(new Test, argc, argv);

    return 0;
}
