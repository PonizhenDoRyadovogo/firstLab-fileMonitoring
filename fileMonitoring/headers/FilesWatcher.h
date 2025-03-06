#ifndef FILESWATCHER_H
#define FILESWATCHER_H

#include <QObject>

#include "IFileMonitor.h"

class FilesWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FilesWatcher(const QStringList &files, IFileMonitor *monitor, QObject *parent = nullptr);
    void checkFiles();
    void setFiles(const QStringList &files);
signals:
    void fileExistsAndNotEmpty(const FileInfo &fileInfo);
    void fileExistsAndChanged(const FileInfo &fileInfo);
    void fileNotExist(const QString &filePath);
private:
    QVector<FileInfo> m_files;
};

#endif // FILESWATCHER_H
