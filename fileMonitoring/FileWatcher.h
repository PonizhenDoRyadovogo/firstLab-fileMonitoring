#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>

#include "FileInfo.h"

class FileWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileWatcher(const QStringList &files, QObject *parent = nullptr);

signals:
    void fileExistsAndNotEmpty(const FileInfo &fileInfo);
    void fileExistsAndChanged(const FileInfo &fileInfo);
    void fileNotExist(const FileInfo &fileInfo);
private:
    QVector<FileInfo> m_files;
};

#endif // FILEWATCHER_H
