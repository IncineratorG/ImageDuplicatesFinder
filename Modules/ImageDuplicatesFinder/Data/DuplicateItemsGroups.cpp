#include "DuplicateItemsGroups.h"
#include "IdGenerator.h"



DuplicateItemsGroups::DuplicateItemsGroups() {
    id = IdGenerator::getInstance()->getNextId();
}

DuplicateItemsGroups::DuplicateItemsGroups(const QList<DuplicateItemsGroup>& groupsList)
    : m_groupsList(groupsList)
{
    id = IdGenerator::getInstance()->getNextId();
}

DuplicateItemsGroups::DuplicateItemsGroups(const DuplicateItemsGroups& other)
    : m_groupsList(other.m_groupsList)
{
    id = IdGenerator::getInstance()->getNextId();
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

qint64 DuplicateItemsGroups::getId() const {
    return id;
}

QList<DuplicateItemsGroup> DuplicateItemsGroups::getGroupsList() const {
    return m_groupsList;
}
