#include "FilesWatcher.h"

#include <QDir>
#include <QFileInfo>
#include <QFileSystemWatcher>
#include <QMutex>
#include <QMap>

#include <ranges>

namespace Settings {

FilesWatcher* FilesWatcher::self = 0;

QMap<QString, QStringList> currentDirs;
QFileSystemWatcher* systemFileWatcher;
QMutex mutex;

FilesWatcher::FilesWatcher()
{
    systemFileWatcher = new QFileSystemWatcher();
}

FilesWatcher::~FilesWatcher()
{
    delete systemFileWatcher;
}

FilesWatcher* FilesWatcher::getSelf()
{
    if (!self) {
        self = new FilesWatcher();
        
        connect(systemFileWatcher, &QFileSystemWatcher::directoryChanged, self, &FilesWatcher::directoryUpdated);
    }
    
    return self;
}

auto FilesWatcher::addWatchPath(const QString& path) -> bool
{
    QMutexLocker locker(&mutex);

    systemFileWatcher->addPath(path);

    QFileInfo f(path);

    if (f.isDir()) {
        const QDir dirw(path);
        currentDirs[path] = dirw.entryList(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files, QDir::DirsFirst);

        return true;
    } else {
        return false;
    }
}

auto FilesWatcher::directoryUpdated(const QString& path) -> void
{
    QMutexLocker locker(&mutex);

    QStringList oldFilesList = currentDirs[path];
    const QDir dir(path);

    QStringList newFilesList = dir.entryList(QDir::NoDotAndDotDot  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);

    oldFilesList.sort();
    newFilesList.sort();

    if (oldFilesList.length() == newFilesList.length()) { // rename files
        QStringList resultFilesList;
        std::ranges::set_difference(oldFilesList, newFilesList, std::back_inserter(resultFilesList));
        std::ranges::set_difference(newFilesList, oldFilesList, std::back_inserter(resultFilesList));

        if (resultFilesList.length() == 2) {
            emit renameFile(resultFilesList.at(0), resultFilesList.at(1));
        }
    } else {
        if (oldFilesList.length() > newFilesList.length()) { // delete files
            QStringList resultFilesList;
            std::ranges::set_difference(oldFilesList, newFilesList, std::back_inserter(resultFilesList));

            foreach (const QString& file, resultFilesList) {
                emit deleteFile(file);
            }

        } else { // new files
            QStringList resultFilesList;
            std::ranges::set_difference(newFilesList, oldFilesList, std::back_inserter(resultFilesList));

            foreach (const QString& file, resultFilesList) {
                emit createFile(file);
            }
        }
    }

    currentDirs[path] = newFilesList;
}

} // namespace Settings
