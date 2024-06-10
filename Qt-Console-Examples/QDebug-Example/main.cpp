#include <QCoreApplication>

#include <QDebug>
#include <SomeModel.h>
#include <Logger.h>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    // Установка логера
    Settings::Logger::instance()->setDebugMessageHandler();

    Models::SomeModel someModel;

    qDebug() << someModel;

    qDebug() << "Debug";
    qInfo() << "Info";
    qWarning() << "Warning";
    qCritical() << "Critical";

    return app.exec();
}
