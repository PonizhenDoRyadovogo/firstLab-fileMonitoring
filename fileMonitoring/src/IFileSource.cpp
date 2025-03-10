#include <QFileInfo>
#include <QDebug>

#include "IFileSource.h"

FileFileSource::FileFileSource(const QString &filePath)
    : m_filePath(filePath)
{
    m_lastModified = QFileInfo(m_filePath).lastModified();
}

QStringList FileFileSource::getFiles()
{
    QStringList result;
    QFile file(m_filePath);

    if(!file.exists()) {
        qDebug() << "Error: file " << m_filePath << "doesn't exist!";
        return result;
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: file " << m_filePath << "can't open!";
        return result;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if(!line.isEmpty()) {
            result.push_back(line);
        }
    }
    file.close();
    result.removeDuplicates();
    return result;
}

bool FileFileSource::canUpdate()
{
    return true;
}

bool FileFileSource::isUpdated()
{
    QFileInfo fileInfo(m_filePath);
    QDateTime newModified = fileInfo.lastModified();

    if(newModified > m_lastModified) {
        m_lastModified = newModified;
        return true;
    }

    return false;
}

QStringList ConsoleFileSource::getFiles()
{
    QStringList result;
    QTextStream in(stdin);
    qDebug() << "Enter files (one in line, empty line for break):";

    while(true) {
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) break;
        result.push_back(line);
    }

    return result;
}
