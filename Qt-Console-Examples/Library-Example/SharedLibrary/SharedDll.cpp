#include "SharedDll.h"

ClassInSharedDLL::ClassInSharedDLL()
{
    // ...
}

ClassInSharedDLL::~ClassInSharedDLL()
{
    // ...
}

auto ClassInSharedDLL::getInfo() -> QString
{
    return QString("This is SHARED_LIBRARY class");
}

auto getInfo() -> QString
{
    return QString("This is SHARED_LIBRARY function");
}
