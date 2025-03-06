#include <QFileInfo>

#include "FilesWatcher.h"

FilesWatcher::FilesWatcher(IFileSource *fileSource, IFileMonitor *monitor, QObject *parent)
    : QObject{parent}, m_fileSource(fileSource)
{
    connect(this, &FilesWatcher::fileNotExist, monitor, &IFileMonitor::onFileNotExisted);
    connect(this, &FilesWatcher::fileExistsAndNotEmpty, monitor, &IFileMonitor::onFileExistedAndNotEmpty);
    connect(this, &FilesWatcher::fileExistsAndChanged, monitor, &IFileMonitor::onFileExistsAndChanged);

    reloadFiles();
}

void FilesWatcher::checkFiles()
{
    if(m_fileSource->canUpdate() && m_fileSource->isUpdated()) {
        reloadFiles();
    }

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

void FilesWatcher::reloadFiles()
{
    QStringList files = m_fileSource->getFiles();
    m_files.clear();
    for(const auto &filePath: files) {
        FileInfo fiObj(filePath);
        QFileInfo check(filePath);
        fiObj.setExists(check.exists());
        fiObj.setSize(static_cast<unsigned int>(check.size()));
        m_files.push_back(fiObj);
    }
}
