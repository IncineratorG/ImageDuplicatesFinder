#ifndef IDFSTORE_H
#define IDFSTORE_H

#include "Storages/Abstract/AbstractStore.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"
#include "Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroups.h"
#include "Modules/ImageDuplicatesFinder/Data/FolderInfoItemsList.h"



class IDFStore : public AbstractStore
{
    Q_OBJECT

public:
    IDFStore();

    void setInputData(const IDFServiceInputData& inputData);
    IDFServiceInputData getInputData() const;

    void setOutputData(const IDFServiceOutputData& outputData);
    IDFServiceOutputData getOutputData() const;

//    void setModelDuplicatesGroups(const DuplicateItemsGroups& modelDuplicatesGroups);
//    DuplicateItemsGroups getModelDuplicatesGroups() const;

signals:
    void inputDataChanged();
    void outputDataChanged();

private:
    IDFServiceInputData m_serviceInputData;
    IDFServiceOutputData m_serviceOutputData;

//    DuplicateItemsGroups m_modelDuplicatesGroups;
//    FolderInfoItemsList m_modelFolderInfoItemsList;
};

#endif // IDFSTORE_H
