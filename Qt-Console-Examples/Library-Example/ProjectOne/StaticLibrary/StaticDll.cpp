#include "StaticDll.h"

ClassInStaticDll::ClassInStaticDll()
{

}

ClassInStaticDll::~ClassInStaticDll()
{

}

auto ClassInStaticDll::getInfo() -> QString
{
    return QString("This is STATIC_LIBRARY class");
}
