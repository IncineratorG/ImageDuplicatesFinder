#include "InputFoldersModelItem.h"



InputFoldersModelItem::InputFoldersModelItem()
    : m_path(""),
      m_processSubpath(true)
{

}

InputFoldersModelItem::InputFoldersModelItem(const QString& path, const bool processSubpath)
    : m_path(path),
      m_processSubpath(processSubpath)
{

}

InputFoldersModelItem::InputFoldersModelItem(const InputFoldersModelItem& other)
    : m_path(other.m_path),
      m_processSubpath(other.m_processSubpath)
{

}

void InputFoldersModelItem::setPath(const QString& path, const bool processSubpath) {
    m_path = path;
    m_processSubpath = processSubpath;
}

QString InputFoldersModelItem::getPath() const {
    return m_path;
}

bool InputFoldersModelItem::getProcessSubpath() const {
    return m_processSubpath;
}
