#ifndef IDFSERVICEDATACONVERTOR_H
#define IDFSERVICEDATACONVERTOR_H

#include <QList>
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h"
#include "Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroups.h"
#include "../Data/IdGenerator.h"



class IDFServiceDataConvertor
{
public:
    IDFServiceDataConvertor();

    DuplicateItemsGroups toDuplicateItemsGroups(const IDFServiceOutputData& serviceOutput) const;

private:
    IdGenerator* m_idGenerator;
};

#endif // IDFSERVICEDATACONVERTOR_H
