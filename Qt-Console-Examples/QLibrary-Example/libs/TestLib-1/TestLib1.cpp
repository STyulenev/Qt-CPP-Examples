#include "TestLib1.h"

#include <iostream>

extern "C" {

void print(const char* const text)
{
    std::cout << "MyLib-1 : " << text << std::endl;
}

const char* getText()
{
    return "Hello from MyLib-1!";
}

}
