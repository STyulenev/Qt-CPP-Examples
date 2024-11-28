#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ImageBox.h"
#include "ImageProvider.h"
#include "SomeModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ImageBox>("MyWidgets", 1, 0, "ImageBox");
    //qmlRegisterType<ColorImageProvider>("ColorImageProvider", 1, 0, "ColorImageProvider");
    qmlRegisterType<SomeModel>("MyWidgets", 1, 0, "SomeModel");

    QQmlApplicationEngine engine;

    engine.addImageProvider(QLatin1String("colors"), new ImageProvider);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
