#include "MainWindow.h"

#include <QApplication>
#include <QTest>

#include <Test_MainWindow.h>

auto main(int argc, char* argv[]) -> int
{
    QApplication a(argc, argv);

    //assert(QTest::qExec(new Test_MainWindow, argc, argv) == 0);
    QTest::qExec(new Test_MainWindow, argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
