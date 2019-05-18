#ifndef PATHS_H
#define PATHS_H

#include <QList>
#include "Path.h"



class Paths
{
public:
    Paths();
    Paths(const QList<Path>& paths);
    Paths(const Paths& other);

    void appendPath(const Path& path);
    QList<Path> getPaths() const;

    void clear();

private:
    QList<Path> m_pathsList;
};

#endif // PATHS_H
