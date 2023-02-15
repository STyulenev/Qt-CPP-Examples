#include "SharedDll.h"

ClassInSharedDLL::ClassInSharedDLL()
{

}

ClassInSharedDLL::~ClassInSharedDLL()
{

}

auto ClassInSharedDLL::getInfo() -> QString
{
    return QString("This is SHARED_LIBRARY class");
}

QString getInfo()
{
    return QString("This is SHARED_LIBRARY function");
}
