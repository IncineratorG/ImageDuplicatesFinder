#ifndef IDFSERVICEDATAWAREHOUSE_H
#define IDFSERVICEDATAWAREHOUSE_H

#include "Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"



class IDFServiceDataWarehouse
{
public:
    IDFServiceDataWarehouse();

    void setInputData(const IDFServiceInputData& inputData);
    IDFServiceInputData getInputData() const;

private:
    IDFServiceInputData m_serviceInputData;
    IDFServiceOutputData m_serviceOutputData;
};

#endif // IDFSERVICEDATAWAREHOUSE_H
