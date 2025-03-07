#ifndef IFILESOURCE_H
#define IFILESOURCE_H

#include <QStringList>
#include <QDateTime>

class IFileSource
{
public:
    virtual ~IFileSource() = default;
    virtual QStringList getFiles() = 0;
};

class IUpdatableFileSource : public IFileSource
{
public:
    virtual bool canUpdate() = 0;
    virtual bool isUpdated() = 0;
};

class FileFileSource : public IUpdatableFileSource
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
