#include "IDFServiceInputDataItem.h"



IDFServiceInputDataItem::IDFServiceInputDataItem()
    : m_path(""),
      m_processSubpath(true)
{

}

IDFServiceInputDataItem::IDFServiceInputDataItem(const QString& path, const bool processSubpath)
    : m_path(path),
      m_processSubpath(processSubpath)
{

}

IDFServiceInputDataItem::IDFServiceInputDataItem(const IDFServiceInputDataItem& other)
    : m_path(other.m_path),
      m_processSubpath(other.m_processSubpath)
{

}

void IDFServiceInputDataItem::setPath(const QString& path, const bool processSubpath) {
    m_path = path;
    m_processSubpath = processSubpath;
}

QString IDFServiceInputDataItem::getPath() const {
    return m_path;
}

bool IDFServiceInputDataItem::getProcessSubpath() const {
    return m_processSubpath;
}
