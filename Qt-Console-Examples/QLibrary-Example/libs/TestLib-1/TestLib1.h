#pragma once

#include "TestLib1Global.h"

extern "C" {

MYLIB1SHARED_EXPORT void print(const char* const text);
MYLIB1SHARED_EXPORT const char* getText();

}
