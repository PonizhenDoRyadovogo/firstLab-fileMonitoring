#include <QFileInfo>

#include "FilesWatcher.h"

FilesWatcher::FilesWatcher(const QStringList &files, FileMonitor *monitor, QObject *parent)
    : QObject{parent}
{
    for(const auto &filePath: files)
    {
        FileInfo fiObj(filePath);
        QFileInfo check(filePath);
        fiObj.setExists(check.exists());
        fiObj.setSize(check.exists() ? static_cast<unsigned int>(check.size()) : 0);
        m_files.push_back(fiObj);
    }

    connect(this, &FilesWatcher::fileNotExist, monitor, &FileMonitor::onFileNotExisted);
    connect(this, &FilesWatcher::fileExistsAndNotEmpty, monitor, &FileMonitor::onFileExistedAndNotEmpty);
    connect(this, &FilesWatcher::fileExistsAndChanged, monitor, &FileMonitor::onFileExistsAndChanged);
}

void FilesWatcher::checkFiles()
{
    for(auto &fileInfo : m_files) {
        QFileInfo realFi(fileInfo.getPath());
        bool currentExists = realFi.exists();
        unsigned int currentSize = static_cast<unsigned int>(realFi.size());

        if(!currentExists) {
            if(fileInfo.isExists()) {
                fileInfo.setExists(false);
                fileInfo.setSize(0);
                emit fileNotExist(fileInfo.getPath());
            }
        } else {
            if(!fileInfo.isExists()) {
                fileInfo.setExists(true);
                fileInfo.setSize(currentSize);
                emit fileExistsAndNotEmpty(fileInfo);
            } else {
                if(currentSize != fileInfo.getSize()) {
                    fileInfo.setSize(currentSize);
                    emit fileExistsAndChanged(fileInfo);
                } else {
                    emit fileExistsAndNotEmpty(fileInfo);
                }
            }
        }
    }
}

void FilesWatcher::setFiles(const QStringList &files)
{
    m_files.clear();

    for(const auto &filePath : files) {
        FileInfo fiObj(filePath);
        QFileInfo check(filePath);
        fiObj.setExists(check.exists());
        fiObj.setSize(check.exists() ? static_cast<unsigned int>(check.size()) : 0);
        m_files.push_back(fiObj);
    }
}
