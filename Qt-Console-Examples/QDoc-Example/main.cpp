/*!
   \page main-module.html

   \title О точки входа main

   Описание

   ...
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "NumericFunctions.h"

/*!
    \fn auto main(int argc, char* argv[]) -> int

    Описание функции auto main(int argc, char* argv[]) -> int
*/
auto main(int argc, char* argv[]) -> int
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    assert(Logic::add(1, 2) == 3);

    QQmlApplicationEngine engine;

    engine.addImportPath(":/qml");
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
