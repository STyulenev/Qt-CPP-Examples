#pragma once

#include <stdexcept>

class ExampleClass
{
public:
    ExampleClass();

    static auto sum(int one, int two) -> int;

    static auto devide(double one, double two) -> double;
};

