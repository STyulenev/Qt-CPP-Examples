#include "ScopeExit.h"

#include <QDebug>

#include <boost/scope_exit.hpp>

auto ScopeExit::ScopeExitExample() -> void
{
    int* value = new int {10};

    BOOST_SCOPE_EXIT(&value) // as a destructor RAII
    {
        delete value;
        // value = 0; - copy of i
        qDebug() << "deleted";
    } BOOST_SCOPE_EXIT_END

    qDebug() << *value; // not 0, random value
}
