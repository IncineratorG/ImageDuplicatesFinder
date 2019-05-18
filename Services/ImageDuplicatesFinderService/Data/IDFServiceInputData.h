#ifndef IDFSERVICEINPUTDATA_H
#define IDFSERVICEINPUTDATA_H

#include <QList>
#include <QDir>
#include "IDFServiceInputDataItem.h"
#include "Paths.h"



class IDFServiceInputData
{
public:
    IDFServiceInputData();
    IDFServiceInputData(const QList<IDFServiceInputDataItem>& inputDataList);
    IDFServiceInputData(const IDFServiceInputData& other);

    void appendInputDataItem(const IDFServiceInputDataItem& item);

    void setInputDataList(const QList<IDFServiceInputDataItem>& inputDataList);

    QList<IDFServiceInputDataItem> getInputDataList() const;

    Paths toPaths();

private:
    QList<IDFServiceInputDataItem> m_inputDataList;

    void toPaths_r(const QDir& directory, Paths& paths);
};

#endif // IDFSERVICEINPUTDATA_H
