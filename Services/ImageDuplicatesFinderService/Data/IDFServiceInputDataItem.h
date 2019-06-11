#ifndef IDFSERVICEINPUTDATAITEM_H
#define IDFSERVICEINPUTDATAITEM_H

#include <QString>



class IDFServiceInputDataItem
{
public:
    IDFServiceInputDataItem();
    IDFServiceInputDataItem(const QString& path, const bool processSubpath = true);
    IDFServiceInputDataItem(const IDFServiceInputDataItem& other);

    void setPath(const QString& path, const bool processSubpath = true);

    QString getPath() const;
    bool getProcessSubpath() const;

    bool operator==(const IDFServiceInputDataItem& other) {
        return this->m_path == other.m_path && this->m_processSubpath == other.m_processSubpath;
    }

private:
    QString m_path;
    bool m_processSubpath;
};

#endif // IDFSERVICEINPUTDATAITEM_H
