#include <QCoreApplication>

#include <QDebug>
#include <SomeModel.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Models::SomeModel someModel;

    qDebug() << someModel;

    return app.exec();
}
