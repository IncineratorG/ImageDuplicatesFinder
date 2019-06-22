#include "DuplicateItem.h"
#include "IdGenerator.h"



DuplicateItem::DuplicateItem()
    : m_imagePath("")
{
    m_id = IdGenerator::getInstance()->getNextId();
}

DuplicateItem::DuplicateItem(const QString& imagePath)
    : m_imagePath(imagePath)
{
    m_id = IdGenerator::getInstance()->getNextId();
}

DuplicateItem::DuplicateItem(const DuplicateItem& other)
    : m_imagePath(other.m_imagePath),
      m_id(other.m_id)
{

}

qint64 DuplicateItem::getId() const {
    return m_id;
}

QString DuplicateItem::getImagePath() const {
    return m_imagePath;
}
