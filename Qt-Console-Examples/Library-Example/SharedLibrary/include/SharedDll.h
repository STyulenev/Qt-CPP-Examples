#pragma once

#include "SharedDllGlobal.h"
#include <QString>

class MYDLL_EXPORT ClassInSharedDLL
{
public:
    ClassInSharedDLL();
    ~ClassInSharedDLL();

    static auto getInfo() -> QString;
};

MYDLL_EXPORT QString getInfo();
