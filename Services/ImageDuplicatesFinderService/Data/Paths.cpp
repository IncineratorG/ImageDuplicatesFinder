#include "Paths.h"



Paths::Paths() {

}

Paths::Paths(const QList<Path>& paths)
    : m_pathsList(paths)
{

}

Paths::Paths(const Paths& other)
    : m_pathsList(other.m_pathsList)
{

}

void Paths::appendPath(const Path& path) {
    m_pathsList.append(path);
}

QList<Path> Paths::getPaths() const {
    return m_pathsList;
}

void Paths::clear() {
    m_pathsList.clear();
}
