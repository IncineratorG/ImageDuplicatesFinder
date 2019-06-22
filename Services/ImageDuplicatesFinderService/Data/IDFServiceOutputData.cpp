#include "IDFServiceOutputData.h"



IDFServiceOutputData::IDFServiceOutputData() {

}

IDFServiceOutputData::IDFServiceOutputData(std::shared_ptr<ImagesDuplicatesGroups> groups)
    : m_duplicatesGroups(groups)
{

}

IDFServiceOutputData::IDFServiceOutputData(const IDFServiceOutputData& other)
    : m_duplicatesGroups(other.m_duplicatesGroups)
{

}

void IDFServiceOutputData::setDuplicatesGroups(std::shared_ptr<ImagesDuplicatesGroups> groups) {
    m_duplicatesGroups = groups;
}

std::shared_ptr<ImagesDuplicatesGroups> IDFServiceOutputData::getDuplicatesGroups() {
    if (m_duplicatesGroups == nullptr) {
        m_duplicatesGroups = std::shared_ptr<ImagesDuplicatesGroups>(new ImagesDuplicatesGroups());
    }

    return m_duplicatesGroups;
}

void IDFServiceOutputData::setFoldersInfos(std::shared_ptr<FoldersInfos> foldersInfos) {
    m_folders_infos = foldersInfos;
}

std::shared_ptr<FoldersInfos> IDFServiceOutputData::getFoldersInfos() {
    if (m_folders_infos == nullptr) {
        m_folders_infos = std::shared_ptr<FoldersInfos>(new FoldersInfos());
    }

    return m_folders_infos;
}
