#include <QCoreApplication>
#include "SharedDll.h"

#include <QDebug>

auto main(int argc, char* argv[]) -> int
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << ClassInSharedDLL::getInfo();
    qDebug() << getInfo();

    return 0;
}
