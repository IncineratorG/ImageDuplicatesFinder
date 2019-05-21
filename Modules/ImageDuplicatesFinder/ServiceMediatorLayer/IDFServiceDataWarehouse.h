#ifndef IDFSERVICEDATAWAREHOUSE_H
#define IDFSERVICEDATAWAREHOUSE_H

#include "Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h"



class IDFServiceDataWarehouse
{
public:
    IDFServiceDataWarehouse();

    void setInputData(const IDFServiceInputData& inputData);
    IDFServiceInputData getInputData() const;

private:
    IDFServiceInputData m_serviceInputData;
};

#endif // IDFSERVICEDATAWAREHOUSE_H
