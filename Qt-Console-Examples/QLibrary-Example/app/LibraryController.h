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

    /*!
     * \brief Функция вызыва библиотечных функций.
     * \details R - тип возвращаемого значения. Args - типы данных аргументов функции.
     * \param libName - название библиотеки
     * \param funcName - название функции
     * \param args - аргументы функции
     * \return значение из функции с типом R
     *
     * Пример для функции print без шаблона.
     * \code
     * typedef void (*PrintFunction)(const char* const);
     * PrintFunction print = (PrintFunction) lib->resolve(funcName.toStdString().c_str());
     * if (print) {
     *   print("some text...");
     * }
     * \endcode
     */
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
