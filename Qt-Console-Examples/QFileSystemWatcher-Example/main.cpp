#include <QCoreApplication>
#include <QDebug>

#include "FilesWatcher.h"

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);

    Settings::FilesWatcher* filesWatcher = Settings::FilesWatcher::getSelf();
    filesWatcher->addWatchPath("..."); // add path

    QObject::connect(filesWatcher, &Settings::FilesWatcher::createFile, [](const QString& file) -> void {
        qDebug() << "New file: " << file;
    });

    QObject::connect(filesWatcher, &Settings::FilesWatcher::deleteFile, [](const QString& file) -> void {
        qDebug() << "Delete file: " << file;
    });

    QObject::connect(filesWatcher, &Settings::FilesWatcher::renameFile, [](const QString& oldFile, const QString& newFile) -> void {
        qDebug() << "Rename file from: " << oldFile << "to" << newFile;
    });

    return app.exec();
}
