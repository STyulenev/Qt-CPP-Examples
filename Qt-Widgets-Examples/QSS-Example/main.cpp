#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QStyleFactory>
#include <QFontDatabase>

auto main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) -> int
{
    QApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/res/font/intermedium.ttf");

    QFile styleFile(":/res/style/style.css");
    if (styleFile.open(QIODevice::ReadOnly)) {
        QString appSlyle = QString(styleFile.readAll());
        qApp->setStyleSheet(appSlyle);
        styleFile.close();
    }

    View::MainWindow w;
    w.show();

    return app.exec();
}
