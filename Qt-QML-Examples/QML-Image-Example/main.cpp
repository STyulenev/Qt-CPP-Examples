#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "QIconImage.h"
#include "ImageProvider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QIconImage>("QIconImage", 1, 0, "QIconImage");
    //qmlRegisterType<ColorImageProvider>("ColorImageProvider", 1, 0, "ColorImageProvider");

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
