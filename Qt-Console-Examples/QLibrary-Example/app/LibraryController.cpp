#include "LibraryController.h"

LibraryController::LibraryController(const QString path, const QStringList& libList) :
    _path(path),
    _libList(libList)
{

}

LibraryController::~LibraryController()
{
    for (QLibrary* value : _libMap) {
        delete value;
    }
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
        QLibrary* lib = new QLibrary(libName);

        if (!lib || !lib->load()) {
            qDebug() << libName << " loading failed!";
        } else {
            qDebug() << libName << " was loaded successful!";
            _libMap.insert(_lib, lib);
        }
    }
}
