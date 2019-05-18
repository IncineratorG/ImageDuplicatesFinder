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
