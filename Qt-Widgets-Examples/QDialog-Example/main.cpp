#include "MainWindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

auto main(int argc, char* argv[]) -> int
{
    QApplication app(argc, argv);

    // Set local language for Standart QMessageBox and other
    QTranslator translator;
    if (translator.load(QLocale::system(), "qt", "_", QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        app.installTranslator(&translator);
    } else {
        // error
    }

    Views::MainWindow w;
    w.show();
    return app.exec();
}
