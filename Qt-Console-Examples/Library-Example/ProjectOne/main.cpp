#include <QCoreApplication>
#include "SharedDLL.h"
#include "StaticDll.h"

#include <QDebug>

auto main(int argc, char* argv[]) -> int
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << ClassInSharedDLL::getInfo();
    qDebug() << getInfo();
    qDebug() << ClassInStaticDll::getInfo();

    return 0;
}
