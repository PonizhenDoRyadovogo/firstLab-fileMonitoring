#include <iostream>

#include "FileMonitor.h"

void FileMonitor::onFileExistedAndNotEmpty(const FileInfo &fileInfo)
{
    std::cout<<"File " << fileInfo.getPath().toStdString() << " exists, size: " << fileInfo.getSize();
}

void FileMonitor::onFileExistsAndChanged(const FileInfo &fileInfo)
{
    std::cout<<"File " << fileInfo.getPath().toStdString() << " changed, size: " << fileInfo.getSize();
}

void FileMonitor::onFileNotExisted(const QString &filePath)
{
    std::cout << "File " << filePath.toStdString() << " deleted";
}
