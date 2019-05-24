#include "InputFolderItem.h"



InputFolderItem::InputFolderItem()
    : m_path(""),
      m_processSubpath(true)
{

}

InputFolderItem::InputFolderItem(const QString& path, const bool processSubpath)
    : m_path(path),
      m_processSubpath(processSubpath)
{

}

InputFolderItem::InputFolderItem(const InputFolderItem& other)
    : m_path(other.m_path),
      m_processSubpath(other.m_processSubpath)
{

}

void InputFolderItem::setPath(const QString& path, const bool processSubpath) {
    m_path = path;
    m_processSubpath = processSubpath;
}

QString InputFolderItem::getPath() const {
    return m_path;
}

bool InputFolderItem::getProcessSubpath() const {
    return m_processSubpath;
}
