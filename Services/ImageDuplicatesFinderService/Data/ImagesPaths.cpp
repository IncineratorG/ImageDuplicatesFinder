#include "ImagesPaths.h"



ImagesPaths::ImagesPaths() {

}

ImagesPaths::ImagesPaths(const QList<ImagePath>& paths)
    : m_pathsList(paths)
{

}

ImagesPaths::ImagesPaths(const ImagesPaths& other)
    : m_pathsList(other.m_pathsList)
{

}

void ImagesPaths::appendImagePath(const ImagePath& path) {
    m_pathsList.append(path);
}

QList<ImagePath> ImagesPaths::getPaths() const {
    return m_pathsList;
}

void ImagesPaths::clear() {
    m_pathsList.clear();
}
