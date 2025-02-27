#include "FileInfo.h"

QString FileInfo::getPath() const
{
    return m_filePath;
}

unsigned int FileInfo::getSize() const
{
    return m_size;
}

bool FileInfo::isExists() const
{
    return m_exists;
}
