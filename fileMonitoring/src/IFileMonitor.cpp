#include <QDebug>

#include "IFileMonitor.h"

void ConsoleFileMonitor::onFileExistedAndNotEmpty(const FileInfo &fileInfo)
{
    qDebug() <<"File " << fileInfo.getPath() << " exists, size: " << fileInfo.getSize();
}

void ConsoleFileMonitor::onFileExistsAndChanged(const FileInfo &fileInfo)
{
    qDebug() <<"File " << fileInfo.getPath() << " changed, size: " << fileInfo.getSize();
}

void ConsoleFileMonitor::onFileNotExisted(const QString &filePath)
{
    qDebug() << "File " << filePath << " deleted";
}
