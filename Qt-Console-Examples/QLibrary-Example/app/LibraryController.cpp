#include "LibraryController.h"




LibraryController::LibraryController(const QString path, const QStringList& libList) :
    _path(path),
    _libList(libList)
{

}

LibraryController::~LibraryController()
{

}

void LibraryController::launch()
{
    QString preffix = "lib";
    QString suffix = ""; // "d";
    QString type = "";

#ifdef UNIX
    type = "so";
#elif WIN32
    type = "dll";
#elif

#endif

    for (const QString& _lib : _libList) {
        QString libName = QString("%0%1%2%3.%4").arg(_path).arg(preffix).arg(_lib).arg(suffix).arg(type);
        QLibrary * lib = new QLibrary(libName);

        if (!lib || !lib->load()) {
            qDebug() << libName << " loading failed!";
        } else {
            qDebug() << libName << " was loaded successful!";
            _libMap.insert(_lib, lib);
        }
    }



    //"libMyLib-1.dll"
    /*static const QString libName = QString("%0%1%2.%3").arg(preffix).arg("MyLib-1").arg(suffix).arg(type);

    qDebug() << LIB_NAME;

    QLibrary lib (LIB_NAME);
    if (!lib.load()) {
        qDebug() << "Loading failed!";
        return false;
    }

    typedef void (*PrintF)(const char* const);
    PrintF print = (PrintF) lib.resolve("inputTest");
    if (print) {
        print("Hello to MyLib!");
    }

    typedef const char* (*GetTestF)();
    GetTestF getText = (GetTestF) lib.resolve("getText");
    if (getText) {
        qDebug() << getText();
    }

    return true;*/
}
