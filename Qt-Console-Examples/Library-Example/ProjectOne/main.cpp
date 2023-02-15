#include <QCoreApplication>
#include "SharedDLL.h"
#include "StaticDll.h"

#include <QDebug>

int main(int argc, char* argv[])
{
    qDebug() << ClassInSharedDLL::getInfo();
    qDebug() << getInfo();
    qDebug() << ClassInStaticDll::getInfo();

    return 0;
}
