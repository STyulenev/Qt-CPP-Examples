#include <celero/Celero.h>

#include "NumericFunctions.h"

CELERO_MAIN
/*int main(int argc, char* argv[])
{
    celero::Run(argc, arv);

    return 0;
}*/

class Test_NumericFunctions : public celero::TestFixture
{
public:
    Test_NumericFunctions()
    {

    }

    inline bool testAdd(const int first, int const two) {
        Logic::Numeric className(first, two);

        return className.add() == (first + two);
    }

    inline bool testSub(const int first, int const two) {
        Logic::Numeric className(first, two);

        return className.sub() == (first - two);
    }

    inline bool testDiv(const int first, int const two)
    {
        Logic::Numeric className(first, two);

        try {
            return className.div() == (first / two);
        } catch (...) {
            return false;
        }
    }

    inline bool testCopyQVector()
    {
        Logic::testCopyQVector();

        return true;
    }

    inline bool testAssigmentQVector()
    {
        Logic::testAssigmentQVector();

        return true;
    }

};

BASELINE_F(NumericFunctions, testAdd, Test_NumericFunctions, 100, 5000)
{
    celero::DoNotOptimizeAway(testAdd(2, 3));
}

BENCHMARK_F(NumericFunctions, testSub, Test_NumericFunctions, 100, 5000)
{
    celero::DoNotOptimizeAway(testSub(5, 5));
}

BENCHMARK_F(NumericFunctions, testDiv, Test_NumericFunctions, 100, 5000)
{
    celero::DoNotOptimizeAway(testDiv(5, 5));
}

BENCHMARK_F(NumericFunctions, testCopyQVector, Test_NumericFunctions, 100, 5000)
{
    celero::DoNotOptimizeAway(testCopyQVector());
}

BENCHMARK_F(NumericFunctions, testAssigmentQVector, Test_NumericFunctions, 100, 5000)
{
    celero::DoNotOptimizeAway(testAssigmentQVector());
}
