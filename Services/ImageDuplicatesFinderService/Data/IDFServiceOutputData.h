#ifndef IDFSERVICEOUTPUTDATA_H
#define IDFSERVICEOUTPUTDATA_H

#include "ImagesDuplicatesGroups.h"
#include <memory>



class IDFServiceOutputData
{
public:
    IDFServiceOutputData();
    IDFServiceOutputData(std::shared_ptr<ImagesDuplicatesGroups> groups);
    IDFServiceOutputData(const IDFServiceOutputData& other);

    void setDuplicatesGroups(std::shared_ptr<ImagesDuplicatesGroups> groups);
    std::shared_ptr<ImagesDuplicatesGroups> getDuplicatesGroups();

private:
    std::shared_ptr<ImagesDuplicatesGroups> m_duplicatesGroups;
};


#endif // IDFSERVICEOUTPUTDATA_H
