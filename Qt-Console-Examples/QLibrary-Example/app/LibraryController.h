#pragma once

#include <QLibrary>
#include <QMap>
#include <QStringList>

#include <QDebug>

class LibraryController
{
public:
    LibraryController(const QString path, const QStringList& libList = {});
    ~LibraryController();

    void launch();

    template <class R, typename... Args>
    R callFunc(QString libName, QString funcName, Args... args) {
        if (_libMap.contains(libName)) {
            QLibrary* lib = _libMap.value(libName);

            if (!lib->isLoaded()) {
                qDebug() << "Error #1";
            }
\
            typedef R (*Function)(Args... args);
            Function func = (Function) lib->resolve(funcName.toStdString().c_str());

            if (func) {
                return func(args...);
            } else {
                qDebug() << "Error #2";
            }
        } else {
            qDebug() << "Error #3";
            throw std::bad_function_call();
        }
    }

private:
    QString _path;
    QStringList _libList;
    QMap<QString, QLibrary*> _libMap;


};
