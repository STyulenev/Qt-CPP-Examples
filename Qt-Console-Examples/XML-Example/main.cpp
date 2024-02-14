#include <QCoreApplication>

#include "ListOfPeolpe.h"
#include <QDebug>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    ListOfPeolpe people;
    qDebug() << people.getXmlAsString();

    return app.exec();
}
