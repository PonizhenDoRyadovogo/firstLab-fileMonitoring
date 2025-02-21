#ifndef FILEINFO_H
#define FILEINFO_H

#include <QString>


class FileInfo
{
public:
    explicit FileInfo(const QString &path)
        :m_filePath(path), m_size(0), m_exists(false)
    {}
    void update();
    QString getPath() const;
    unsigned int getSize() const;
    bool isExists() const;
private:
    QString m_filePath;
    unsigned int m_size;
    bool m_exists;
};

#endif // FILEINFO_H
