#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Circle.h"
#include "DateTime.h"
#include "Enums.h"

#include "AssyncController.h"

auto main(int argc, char* argv[]) -> int
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Components::Circle>("CustomVisualType", 1, 0, "Circle");
    qmlRegisterType<Components::DateTime>("CustomNonVisualType", 1, 0, "DateTime");

    qmlRegisterUncreatableMetaObject(
        ExampleEnums::staticMetaObject,
        "CPPEnums",
        1, 0,
        "ColorEnum",
        "Error: only enums"
    );

    qmlRegisterType<Controllers::AssyncController>("Controllers", 1, 0, "AssyncController");

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
