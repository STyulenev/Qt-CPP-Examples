#include "exampleclass.h"

ExampleClass::ExampleClass()
{

}

auto ExampleClass::sum(int one, int two) -> int
{
    return one + two;
}

auto ExampleClass::devide(double one, double two) -> double
{
    if (two == 0)
        throw std::domain_error("devide by zero");

    return one/two;
}
