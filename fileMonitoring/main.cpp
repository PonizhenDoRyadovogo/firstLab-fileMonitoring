#include <QCoreApplication>
#include <thread>
#include <QDir>
#include <QDebug>
#include <iostream>

#include "FilesWatcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Current directory:" << QDir::currentPath();
    QStringList filesWatch = {"file1.txt", "file2.txt"};
    IFileMonitor *consoleMonitor = new ConsoleFileMonitor();
    FileMonitor *monitor = new FileMonitor(consoleMonitor);
    FilesWatcher watcher(filesWatch, monitor);

    while(true) {
        watcher.checkFiles();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
