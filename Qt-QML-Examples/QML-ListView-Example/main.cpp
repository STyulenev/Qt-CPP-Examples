#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ListModel.h"

#include "DishModel.h"
#include "DishListModel.h"

auto main(int argc, char* argv[]) -> int
{
    QGuiApplication app(argc, argv);

    // Register C ++ type to QML
    qmlRegisterType<ViewModels::ListModel>("ListModels",     0, 1, "ListModel");
    qmlRegisterType<Models::DishModel>("ListModels",         0, 1, "DishModel");
    qmlRegisterType<ViewModels::DishListModel>("ListModels", 0, 1, "DishListModel");

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
