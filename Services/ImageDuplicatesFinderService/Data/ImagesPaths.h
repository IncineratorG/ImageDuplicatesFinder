#ifndef IMAGESPATHS_H
#define IMAGESPATHS_H

#include <QList>
#include "ImagePath.h"



class ImagesPaths
{
public:
    ImagesPaths();
    ImagesPaths(const QList<ImagePath>& paths);
    ImagesPaths(const ImagesPaths& other);

    void appendImagePath(const ImagePath& path);
    QList<ImagePath> getPaths() const;

    void clear();

    bool containImagePath(const ImagePath& path) const;

private:
    QList<ImagePath> m_pathsList;
};

#endif // IMAGESPATHS_H
