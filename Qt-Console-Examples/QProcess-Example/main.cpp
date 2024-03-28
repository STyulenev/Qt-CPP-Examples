#include "ConsoleProcess.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    Controller::ConsoleProcess consoleProces;

    QObject::connect(&consoleProces, &Controller::ConsoleProcess::resultProcess, /*this,*/ [](const QString& program, const QString& result) -> void {
        qDebug() << program << "result:" << result;
    });

    QObject::connect(&consoleProces, &Controller::ConsoleProcess::errorProcess, /*this,*/ [](const QString& program, const QString& error) -> void {
        qDebug() << program << "error:" << error;
    });


    if (!consoleProces.getCurrentDirectoryPath()) {
        // ...
    }

    return app.exec();
}
