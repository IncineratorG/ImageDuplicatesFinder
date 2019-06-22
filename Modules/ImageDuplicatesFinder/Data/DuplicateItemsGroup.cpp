#include "DuplicateItemsGroup.h"
#include "IdGenerator.h"



DuplicateItemsGroup::DuplicateItemsGroup() {
    m_id = IdGenerator::getInstance()->getNextId();
}

DuplicateItemsGroup::DuplicateItemsGroup(const QList<DuplicateItem>& itemsList)
    : m_duplicatesList(itemsList)
{
    m_id = IdGenerator::getInstance()->getNextId();
}

DuplicateItemsGroup::DuplicateItemsGroup(const DuplicateItemsGroup& other)
    : m_duplicatesList(other.m_duplicatesList),
      m_id(other.m_id)
{

}

bool DuplicateItemsGroup::isEmpty() const {
    return m_duplicatesList.isEmpty();
}

bool DuplicateItemsGroup::contains(const qint64 itemId) const {
    for (int i = 0; i < m_duplicatesList.size(); ++i) {
        if (m_duplicatesList.at(i).getId() == itemId) {
            return true;
        }
    }

    return false;
}

void DuplicateItemsGroup::clear() {
    m_duplicatesList.clear();
}

void DuplicateItemsGroup::appendDuplicate(const DuplicateItem& item) {
    m_duplicatesList.append(item);
}

void DuplicateItemsGroup::removeDuplicate(const DuplicateItem& item) {
    m_duplicatesList.removeAll(item);
}

void DuplicateItemsGroup::removeDuplicateAtPosition(const int position) {
    if (position < 0 || position >= m_duplicatesList.size()) {
        return;
    }

    m_duplicatesList.removeAt(position);
}

void DuplicateItemsGroup::removeDuplicateById(const qint64 itemId) {
    for (int i = 0; i < m_duplicatesList.size(); ++i) {
        if (m_duplicatesList.at(i).getId() == itemId) {
            m_duplicatesList.removeAt(i);
            return;
        }
    }
}

qint64 DuplicateItemsGroup::getId() const {
    return m_id;
}

int DuplicateItemsGroup::getGroupSize() const {
    return m_duplicatesList.size();
}

QList<DuplicateItem> DuplicateItemsGroup::getDuplicateItemsList() const {
    return m_duplicatesList;
}
