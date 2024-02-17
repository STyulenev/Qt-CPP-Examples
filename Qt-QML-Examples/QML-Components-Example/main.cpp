#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Circle.h"
#include "DateTime.h"

auto main(int argc, char* argv[]) -> int
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Circle>("CustomVisualType", 1, 0, "Circle");
    qmlRegisterType<DateTime>("CustomNonVisualType", 1, 0, "DateTime");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/qml");

    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
