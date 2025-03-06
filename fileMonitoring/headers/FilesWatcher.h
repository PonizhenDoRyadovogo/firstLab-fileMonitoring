#ifndef FILESWATCHER_H
#define FILESWATCHER_H

#include <QObject>

#include "IFileMonitor.h"
#include "IFileSource.h"

class FilesWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FilesWatcher(IFileSource *fileSource, IFileMonitor *monitor, QObject *parent = nullptr);
    void checkFiles();
    void reloadFiles();
signals:
    void fileExistsAndNotEmpty(const FileInfo &fileInfo);
    void fileExistsAndChanged(const FileInfo &fileInfo);
    void fileNotExist(const QString &filePath);
private:
    IFileSource *m_fileSource;
    QVector<FileInfo> m_files;
};

#endif // FILESWATCHER_H
