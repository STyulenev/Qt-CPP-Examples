/*!
   \page logic-module.html

   \title О модуле Logic

   Описание

   ...
*/
#include "NumericFunctions.h"

/*!
    \namespace Logic

    \brief Описания пространства имён Logic
*/
namespace Logic {

/*!
    \fn int add(const int firstNumber, const  int secondNumber)

    Описание функции int add(const int firstNumber, const  int secondNumber)
*/
int add(const int firstNumber, const int secondNumber)
{
    return firstNumber + secondNumber;
}

/*!
    \fn int sub(const int firstNumber, const  int secondNumber)

    Описание функции int sub(const int firstNumber, const  int secondNumber)
*/
int sub(const int firstNumber, const int secondNumber)
{
    return firstNumber - secondNumber;
}

} // namespace Logic
