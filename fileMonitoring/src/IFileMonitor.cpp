#include <iostream>

#include "IFileMonitor.h"

void ConsoleFileMonitor::onFileExistedAndNotEmpty(const FileInfo &fileInfo)
{
    std::cout<<"File " << fileInfo.getPath().toStdString() << " exists, size: " << fileInfo.getSize() << std::endl;
}

void ConsoleFileMonitor::onFileExistsAndChanged(const FileInfo &fileInfo)
{
    std::cout<<"File " << fileInfo.getPath().toStdString() << " changed, size: " << fileInfo.getSize() << std::endl;
}

void ConsoleFileMonitor::onFileNotExisted(const QString &filePath)
{
    std::cout << "File " << filePath.toStdString() << " deleted" << std::endl;
}
