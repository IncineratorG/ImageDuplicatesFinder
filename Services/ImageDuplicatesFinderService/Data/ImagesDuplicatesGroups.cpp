#include "ImagesDuplicatesGroups.h"



ImagesDuplicatesGroups::ImagesDuplicatesGroups() {

}

ImagesDuplicatesGroups::ImagesDuplicatesGroups(const ImagesDuplicatesGroups& other)
    : m_groupsList(other.m_groupsList)
{

}

void ImagesDuplicatesGroups::clear() {
    m_groupsList.clear();
}

void ImagesDuplicatesGroups::appendGroup(const ImageDuplicatesGroup& group) {
    m_groupsList.append(group);
}

bool ImagesDuplicatesGroups::removeGroup(const int position) {
    if (position < 0 || position >= m_groupsList.size()) {
        return false;
    }

    m_groupsList.removeAt(position);

    return true;
}

QList<ImageDuplicatesGroup> ImagesDuplicatesGroups::getGroupsList() const {
    return m_groupsList;
}

int ImagesDuplicatesGroups::getGroupPosition(const ImageDuplicatesGroup& group) {
    for (int i = 0; i < m_groupsList.size(); ++i) {
        if (m_groupsList.at(i) == group) {
            return i;
        }
    }

    return -1;
}
