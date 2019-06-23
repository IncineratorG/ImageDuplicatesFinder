#ifndef IDFSERVICEDATACONVERTOR_H
#define IDFSERVICEDATACONVERTOR_H

#include <QList>
#include "IDFServiceDataWarehouse.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"
#include "Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroups.h"
#include "../Data/IdGenerator.h"



class IDFServiceDataConvertor
{
public:
    IDFServiceDataConvertor();

    void convertAndSave(const IDFServiceOutputData& serviceOutputData,
                        IDFServiceDataWarehouse* dataWarehouse) const;

private:
    IdGenerator* m_idGenerator;

    DuplicateItemsGroups getDuplicateItemsGroups(const IDFServiceOutputData& serviceOutputData) const;
    FolderInfoItemsList getFolderInfoItemsList(const DuplicateItemsGroups& duplicateItemsGroups) const;
};

#endif // IDFSERVICEDATACONVERTOR_H
