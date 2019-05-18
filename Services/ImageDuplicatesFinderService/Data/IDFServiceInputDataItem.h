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

private:
    QString m_path;
    bool m_processSubpath;
};

#endif // IDFSERVICEINPUTDATAITEM_H
