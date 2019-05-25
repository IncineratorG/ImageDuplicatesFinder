#ifndef IDFSERVICEDATACONVERTOR_H
#define IDFSERVICEDATACONVERTOR_H

#include <QList>
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"
#include "Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroups.h"



class IDFServiceDataConvertor
{
public:
    IDFServiceDataConvertor();

    DuplicateItemsGroups toDuplicateItemsGroups(const IDFServiceOutputData& serviceOutput) const;
};

#endif // IDFSERVICEDATACONVERTOR_H
