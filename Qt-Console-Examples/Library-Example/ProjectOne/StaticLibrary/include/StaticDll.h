#pragma once

#include <QString>

class ClassInStaticDll
{
public:
    ClassInStaticDll();
    ~ClassInStaticDll();

    static auto getInfo() -> QString;
};

