#include "DuplicateItem.h"



DuplicateItem::DuplicateItem()
    : m_imagePath("")
{

}

DuplicateItem::DuplicateItem(const QString& imagePath)
    : m_imagePath(imagePath)
{

}

DuplicateItem::DuplicateItem(const DuplicateItem& other)
    : m_imagePath(other.m_imagePath)
{

}

QString DuplicateItem::getImagePath() const {
    return m_imagePath;
}
