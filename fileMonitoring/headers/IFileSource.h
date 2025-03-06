#ifndef IFILESOURCE_H
#define IFILESOURCE_H

#include <QStringList>
#include <QDateTime>

class IFileSource
{
public:
    virtual ~IFileSource() = default;
    virtual QStringList getFiles() = 0;
    virtual bool canUpdate() {return false;}
    virtual bool isUpdated() {return false;}
};

class FileFileSource : public IFileSource
{
public:
    FileFileSource(const QString &filePath);
    QStringList getFiles() override;
    bool canUpdate() override;
    bool isUpdated() override;
private:
    QString m_filePath;
    QDateTime m_lastModified;
};

class ConsoleFileSource : public IFileSource
{
    QStringList getFiles() override;
};

#endif // IFILESOURCE_H
