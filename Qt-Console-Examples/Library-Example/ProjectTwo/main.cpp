#include <QCoreApplication>
#include "SharedDll.h"

#include <QDebug>

int main(int argc, char* argv[])
{
    qDebug() << ClassInSharedDLL::getInfo();
    qDebug() << getInfo();

    return 0;
}
