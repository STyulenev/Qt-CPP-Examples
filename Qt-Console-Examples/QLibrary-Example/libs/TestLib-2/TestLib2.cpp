#include "TestLib2.h"

extern "C" {

int add(const int firstNumber, const int secondNumber)
{
    return firstNumber + secondNumber;
}

int sub(const int firstNumber, const int secondNumber)
{
    return firstNumber - secondNumber;
}

}
