#include "BoostFunction.h"

#include <boost/function.hpp>

int power(int number)
{
    return number * 2;
}

int power_3(int number)
{
    return number * 2 * 2;
}

auto BoostFunction::exampleBoostFunction() -> void
{
    boost::function<int(int)> func;

    func = &power;
    qDebug() << "2 power 2 =" << func(2);

    func = &power_3;
    qDebug() << "2 power 3 =" << func(2);

    try {
        boost::function<int(int)> func2;
        func2(4);
    } catch (boost::bad_function_call& error) {
        qDebug() << error.what();
    }

    // as lambda
    func = [](int number) -> int {
        return number * 2 * 2 * 2;
    };

    qDebug() << "2 power 4 =" << func(2);
}

struct sum
{
    int sum_int(int first, int& second)
    {
        return first + second;
    }
};

auto BoostFunction::exampleBoostFunctionBinding() -> void
{
    boost::function<int(sum*, int, int&)> f = &sum::sum_int;
    sum s;
    int second = 2;
    qDebug() << "answer =" << f(&s, 1, std::ref(second));
}
