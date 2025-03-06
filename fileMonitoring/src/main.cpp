#include <QCoreApplication>
#include <thread>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDateTime>

#include <QDebug>
#include <QDir>

#include "FilesWatcher.h"

QStringList readListOffFiles(const QString &fileName)
{
    QStringList result;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return result;
    }
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if(!line.isEmpty()) {
            result.push_back(line);
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString pathCache;
    QTextStream inputStream(stdin);
    std::cout<<"Enter the path to the file that contains the names of the files to track: " << std::endl;
    pathCache = inputStream.readLine();

    QStringList oldList = readListOffFiles(pathCache);
    while(oldList.empty()) {
        std::cout<<"Couldn't open the file '" << pathCache.toStdString() << "'.Enter the path to the file again!" <<std::endl;
        pathCache = inputStream.readLine();
        readListOffFiles(pathCache);
    }

    QFileInfo cacheInfo(pathCache);
    QDateTime oldModified = cacheInfo.lastModified();
    IFileMonitor *consoleMonitor = new ConsoleFileMonitor();
    FilesWatcher watcher(oldList, consoleMonitor);

    while(true) {
        QFileInfo currentInfo(pathCache);
        QDateTime newModified = currentInfo.lastModified();
        if(newModified != oldModified) {
            oldModified = newModified;
            QStringList newList = readListOffFiles(pathCache);
            while(newList.empty()) {
                std::cout<<"Couldn't open the file '" << pathCache.toStdString() << "'.Enter the path to the file again!" <<std::endl;
                pathCache = inputStream.readLine();
                readListOffFiles(pathCache);
            }
            if(newList != oldList) {
                watcher.setFiles(newList);
                oldList = newList;
            }
        }

        watcher.checkFiles();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
