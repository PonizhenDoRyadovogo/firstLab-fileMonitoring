#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>

#include "FileInfo.h"

class FileMonitor : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitor(QObject *parent = nullptr)
        :QObject(parent)
    {}
public slots:
    void onFileExistedAndNotEmpty(const FileInfo &fileInfo);
    void onFileExistsAndChanged(const FileInfo &fileInfo);
    void onFileNotExisted(const QString &filePath);
};

#endif // FILEMONITOR_H
