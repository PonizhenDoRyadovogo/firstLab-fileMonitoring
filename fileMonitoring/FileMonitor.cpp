#include <iostream>

#include "FileMonitor.h"

void ConsoleFileMonitor::fileExists(const FileInfo &fileInfo)
{
    std::cout<<"File " << fileInfo.getPath().toStdString() << " exists, size: " << fileInfo.getSize() << std::endl;
}

void ConsoleFileMonitor::fileChanged(const FileInfo &fileInfo)
{
    std::cout<<"File " << fileInfo.getPath().toStdString() << " changed, size: " << fileInfo.getSize() << std::endl;
}

void ConsoleFileMonitor::fileDoesNotExist(const QString &filePath)
{
    std::cout << "File " << filePath.toStdString() << " deleted" << std::endl;
}

void FileMonitor::onFileExistedAndNotEmpty(const FileInfo &fileInfo)
{
    if(m_monitor)
        m_monitor->fileExists(fileInfo);
}

void FileMonitor::onFileExistsAndChanged(const FileInfo &fileInfo)
{
    if(m_monitor)
        m_monitor->fileChanged(fileInfo);
}

void FileMonitor::onFileNotExisted(const QString &filePath)
{
    if(m_monitor)
        m_monitor->fileDoesNotExist(filePath);
}
