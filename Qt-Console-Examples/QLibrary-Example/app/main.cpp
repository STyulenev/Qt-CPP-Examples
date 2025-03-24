#include "LibraryController.h"

int main() {
    const QString path = "C:/Work/QLibrary-Example/";
    const QStringList libList = {
                                 "TestLib-1",
                                 "TestLib-2"
    };

    LibraryController libraryController(path, libList);

    libraryController.launch();

    libraryController.callFunc<void>("TestLib-1", "print", "string");
    qDebug() << libraryController.callFunc<const char*>("TestLib-1", "getText");
    qDebug() << "add = " << libraryController.callFunc<int>("TestLib-2", "add", 1, 2);
    qDebug() << "sub = " << libraryController.callFunc<int>("TestLib-2", "sub", 1, 2);

    return 0;
}
