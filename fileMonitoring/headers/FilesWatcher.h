#ifndef FILESWATCHER_H
#define FILESWATCHER_H

#include <QObject>

#include "IFileMonitor.h"
#include "IFileSource.h"

class FilesWatcher : public QObject
{
    Q_OBJECT
public:
    static FilesWatcher& instance(IFileSource *fileSource, IFileMonitor *monitor)
    {
        static FilesWatcher watcher(fileSource, monitor);
        return watcher;
    }
    void checkFiles();
    void reloadFiles();
private:
    explicit FilesWatcher(IFileSource *fileSource, IFileMonitor *monitor, QObject *parent = nullptr);
    FilesWatcher(const FilesWatcher&);
    FilesWatcher& operator=(const FilesWatcher&);
signals:
    void fileExistsAndNotEmpty(const FileInfo &fileInfo);
    void fileExistsAndChanged(const FileInfo &fileInfo);
    void fileNotExist(const FileInfo &filePath);
private:
    IFileSource *m_fileSource;
    QVector<FileInfo> m_files;
};

#endif // FILESWATCHER_H
