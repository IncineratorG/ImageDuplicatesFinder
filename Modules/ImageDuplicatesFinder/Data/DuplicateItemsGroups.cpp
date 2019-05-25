#include "DuplicateItemsGroups.h"



DuplicateItemsGroups::DuplicateItemsGroups() {

}

DuplicateItemsGroups::DuplicateItemsGroups(const QList<DuplicateItemsGroup>& groupsList)
    : m_groupsList(groupsList)
{

}

DuplicateItemsGroups::DuplicateItemsGroups(const DuplicateItemsGroups& other)
    : m_groupsList(other.m_groupsList)
{

}

void DuplicateItemsGroups::clear() {
    m_groupsList.clear();
}

void DuplicateItemsGroups::appendGroup(const DuplicateItemsGroup& group) {
    m_groupsList.append(group);
}

bool DuplicateItemsGroups::removeGroupAtPosition(const int position) {
    if (position < 0 || position >= m_groupsList.size()) {
        return false;
    }

    m_groupsList.removeAt(position);

    return true;
}

QList<DuplicateItemsGroup> DuplicateItemsGroups::getGroupsList() const {
    return m_groupsList;
}
