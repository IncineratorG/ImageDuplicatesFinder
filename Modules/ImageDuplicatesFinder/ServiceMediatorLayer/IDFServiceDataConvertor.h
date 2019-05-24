#ifndef IDFSERVICEDATACONVERTOR_H
#define IDFSERVICEDATACONVERTOR_H

#include <QList>
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"
#include "Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroup.h"



class IDFServiceDataConvertor
{
public:
    IDFServiceDataConvertor();

    QList<DuplicateItemsGroup> toDuplicateItemsGroupsList(const IDFServiceOutputData& serviceOutput) const;
};

#endif // IDFSERVICEDATACONVERTOR_H
