#ifndef IFILEMONITOR_H
#define IFILEMONITOR_H

#include <QObject>

#include "FileInfo.h"

class IFileMonitor : public QObject
{
    Q_OBJECT
public:
    explicit IFileMonitor(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~IFileMonitor() = default;
public slots:
    virtual void onFileExistedAndNotEmpty(const FileInfo &fileInfo) = 0;
    virtual void onFileExistsAndChanged(const FileInfo &fileInfo) = 0;
    virtual void onFileNotExisted(const QString &filePath) = 0;
};

class ConsoleFileMonitor : public IFileMonitor
{
    Q_OBJECT
public:
    explicit ConsoleFileMonitor(QObject *parent = nullptr) : IFileMonitor(parent) {}
public slots:
    void onFileExistedAndNotEmpty(const FileInfo &fileInfo) override;
    void onFileExistsAndChanged(const FileInfo &fileInfo) override;
    void onFileNotExisted(const QString &filePath) override;
};

#endif // IFILEMONITOR_H
