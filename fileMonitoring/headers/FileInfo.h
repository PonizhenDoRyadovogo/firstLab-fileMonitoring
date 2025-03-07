#ifndef FILEINFO_H
#define FILEINFO_H

#include <QString>


class FileInfo
{
public:
    explicit FileInfo(const QString &path)
        :m_filePath(path), m_size(0), m_exists(false)
    {}
    QString getPath() const;
    void setPath(const QString &p) {m_filePath = p;}
    unsigned int getSize() const;
    void setSize(unsigned int s) {m_size = s;}
    bool isExists() const;
    void setExists(bool e) {m_exists = e;}
private:
    QString m_filePath;
    unsigned int m_size;
    bool m_exists;
};

#endif // FILEINFO_H
