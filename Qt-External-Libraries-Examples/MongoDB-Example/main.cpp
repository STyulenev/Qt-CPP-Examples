#include <QApplication>

#include "MainWindow.h"

auto main(int argc, char* argv[]) -> int
{
    QApplication app(argc, argv);

    Views::MainWindow w;
    w.show();

    return app.exec();
}
