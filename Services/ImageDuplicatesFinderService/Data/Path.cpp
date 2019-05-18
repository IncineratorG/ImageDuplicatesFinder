#include "Path.h"



Path::Path()
    : m_path("")
{

}

Path::Path(const QString& path)
    : m_path(path)
{

}

Path::Path(const Path& other)
    : m_path(other.m_path)
{

}

QString Path::toString() const {
    return m_path;
}
