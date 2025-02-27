#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>

#include "FileInfo.h"

class IFileMonitor
{
public:
    virtual ~IFileMonitor() = default;
    virtual void fileExists(const FileInfo &fileInfo) = 0;
    virtual void fileChanged(const FileInfo &fileInfo) = 0;
    virtual void fileDoesNotExist(const QString &filePath) = 0;
};

class ConsoleFileMonitor : public IFileMonitor
{
public:
    void fileExists(const FileInfo &fileInfo) override;
    void fileChanged(const FileInfo &fileInfo) override;
    void fileDoesNotExist(const QString &filePath) override;
};

class FileMonitor : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitor(IFileMonitor *monitor, QObject *parent = nullptr)
        :QObject(parent), m_monitor(monitor)
    {}
public slots:
    void onFileExistedAndNotEmpty(const FileInfo &fileInfo);
    void onFileExistsAndChanged(const FileInfo &fileInfo);
    void onFileNotExisted(const QString &filePath);
private:
    IFileMonitor *m_monitor = nullptr;
};

#endif // FILEMONITOR_H
