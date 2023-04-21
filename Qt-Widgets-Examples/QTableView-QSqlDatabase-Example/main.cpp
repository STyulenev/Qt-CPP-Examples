#include "MainWindow.h"

#include <QApplication>

auto main(int argc, char* argv[]) -> int
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

/* // std::async
#include "DAO.h"

auto main(int argc, char* argv[]) -> int
{
    auto myLambda = []() -> void {
        int a = 10;
        a = 2.0 * a;
    };

    std::thread thread (myLambda);

    thread.join();


    return 0;

}*/
