#include "DuplicateItem.h"
#include "IdGenerator.h"



DuplicateItem::DuplicateItem()
    : m_imagePath("")
{
    id = IdGenerator::getInstance()->getNextId();
}

DuplicateItem::DuplicateItem(const QString& imagePath)
    : m_imagePath(imagePath)
{
    id = IdGenerator::getInstance()->getNextId();
}

DuplicateItem::DuplicateItem(const DuplicateItem& other)
    : m_imagePath(other.m_imagePath)
{
    id = IdGenerator::getInstance()->getNextId();
}

qint64 DuplicateItem::getId() const {
    return id;
}

QString DuplicateItem::getImagePath() const {
    return m_imagePath;
}
