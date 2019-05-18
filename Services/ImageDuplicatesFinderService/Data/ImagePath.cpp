#include "ImagePath.h"



ImagePath::ImagePath()
    : m_imagePath("")
{

}

ImagePath::ImagePath(const QString& path)
    : m_imagePath(path)
{

}

ImagePath::ImagePath(const ImagePath& other)
    : m_imagePath(other.m_imagePath)
{

}

QString ImagePath::toString() const {
    return m_imagePath;
}
