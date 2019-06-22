#ifndef IDFSERVICEOUTPUTDATA_H
#define IDFSERVICEOUTPUTDATA_H

#include "ImagesDuplicatesGroups.h"
#include "FoldersInfos.h"
#include <memory>



class IDFServiceOutputData
{
public:
    IDFServiceOutputData();
    IDFServiceOutputData(std::shared_ptr<ImagesDuplicatesGroups> groups);
    IDFServiceOutputData(const IDFServiceOutputData& other);

    void setDuplicatesGroups(std::shared_ptr<ImagesDuplicatesGroups> groups);
    std::shared_ptr<ImagesDuplicatesGroups> getDuplicatesGroups();

    void setFoldersInfos(std::shared_ptr<FoldersInfos> foldersInfos);
    std::shared_ptr<FoldersInfos> getFoldersInfos();

private:
    std::shared_ptr<ImagesDuplicatesGroups> m_duplicatesGroups;
    std::shared_ptr<FoldersInfos> m_folders_infos;
};


#endif // IDFSERVICEOUTPUTDATA_H
