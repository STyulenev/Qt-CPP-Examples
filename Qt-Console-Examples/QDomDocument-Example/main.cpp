#include <QCoreApplication>

#include "ListOfPeolpe.h"
#include <QDebug>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    ListOfPeolpe people;

    QString xmlString = people.createXml();
    qDebug() << xmlString;

    return app.exec();
}
