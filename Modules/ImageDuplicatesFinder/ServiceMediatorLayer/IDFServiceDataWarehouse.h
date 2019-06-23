#ifndef IDFSERVICEDATAWAREHOUSE_H
#define IDFSERVICEDATAWAREHOUSE_H

#include "Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"
#include "Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroups.h"
#include "Modules/ImageDuplicatesFinder/Data/FolderInfoItemsList.h"



class IDFServiceDataWarehouse
{
public:
    IDFServiceDataWarehouse();

    void setInputData(const IDFServiceInputData& inputData);
    IDFServiceInputData getInputData() const;

    void setOutputData(const IDFServiceOutputData& outputData);
    IDFServiceOutputData getOutputData() const;

    void setModelDuplicatesGroups(const DuplicateItemsGroups& modelDuplicatesGroups);
    DuplicateItemsGroups getModelDuplicatesGroups() const;
    DuplicateItemsGroup getModelDuplicateItemGroup(const qint64 groupId) const;

    void setModelFolderInfoItemsList(const FolderInfoItemsList& modelFolderInfoItemsList);
    FolderInfoItemsList getModelFolderInfoItemsList() const;

private:
    IDFServiceInputData m_serviceInputData;
    IDFServiceOutputData m_serviceOutputData;

    DuplicateItemsGroups m_modelDuplicatesGroups;
    FolderInfoItemsList m_modelFolderInfoItemsList;
};

#endif // IDFSERVICEDATAWAREHOUSE_H
