#include <QApplication>
#include <FelgoApplication>

#include <QQmlApplicationEngine>
#include <QtQml/qqmlregistration.h>

#include "CustomHttpClient.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<Controllers::CustomHttpClient>("Controllers", 1, 0, "CustomHttpClient");

    FelgoApplication felgo;
    QQmlApplicationEngine engine;

    felgo.initialize(&engine);
    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);
    felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    engine.load(QUrl(felgo.mainQmlFileName()));

    return app.exec();
}
