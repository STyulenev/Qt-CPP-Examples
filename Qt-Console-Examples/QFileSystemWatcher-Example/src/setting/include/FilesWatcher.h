#pragma once

#include <QObject>

class QFileSystemWatcher;

namespace Settings {

class FilesWatcher : public QObject
{
    Q_OBJECT

private:
    static FilesWatcher* self;

    explicit FilesWatcher();
    virtual ~FilesWatcher();

public:
    FilesWatcher(const FilesWatcher&) = delete;
    FilesWatcher& operator=(FilesWatcher&) = delete;
    FilesWatcher(const FilesWatcher&&) = delete;
    FilesWatcher&& operator=(FilesWatcher&&) = delete;

    static FilesWatcher* getSelf();

    auto addWatchPath(const QString& path) -> bool;

private slots:
    auto directoryUpdated(const QString& path) -> void;

signals:
    auto createFile(const QString& file) -> void;
    auto deleteFile(const QString& file) -> void;
    auto renameFile(const QString& oldFile, const QString& newFile) -> void;

};

} // namespace Settings
