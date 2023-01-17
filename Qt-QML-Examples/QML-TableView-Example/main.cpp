#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Add header file
#include "TableModel.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register C ++ type to QML
    qmlRegisterType<ViewModels::TableModel>("TableTable", 0, 1, "TableModel");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.addImportPath("qml/Widgets/");

    for(QString path : engine.importPathList())
        qDebug() << path;

    //const QUrl url(u"qrc:/QML-TableView-Example/main.qml"_qs);
    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
