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

void ConsoleFileMonitor::onFileNotExisted(const FileInfo &fileInfo)
{
    if(fileInfo.isExists()) {
        qDebug() << "File " << fileInfo.getPath() << " deleted";
    }
    else {
        qDebug() << "File " << fileInfo.getPath() << "not exist";
    }
}
