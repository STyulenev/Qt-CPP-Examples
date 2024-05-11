#include "MainWindow.h"

#include <QApplication>

#ifdef USE_TEST_OPTION
// Tests
#include <QTest>
#include <Test_MainWindow.h>
#endif

auto main(int argc, char* argv[]) -> int
{
    QApplication app(argc, argv);

#ifdef USE_TEST_OPTION
    //assert(QTest::qExec(new Test_MainWindow, argc, argv) == 0);
    QTest::qExec(new Tests::Test_MainWindow, argc, argv);
#endif

    Views::MainWindow w;
    w.show();

    return app.exec();
}
