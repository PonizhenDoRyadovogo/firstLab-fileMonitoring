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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = a.applicationDirPath() + "/cache.txt";

    FileFileSource source(path);
    ConsoleFileMonitor monitor;

    FilesWatcher &watcher = FilesWatcher::instance(&source, &monitor);

    while(true) {
        watcher.checkFiles();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
