#include "DuplicateItemsGroup.h"
#include "IdGenerator.h"



DuplicateItemsGroup::DuplicateItemsGroup() {
    id = IdGenerator::getInstance()->getNextId();
}

DuplicateItemsGroup::DuplicateItemsGroup(const QList<DuplicateItem>& itemsList)
    : m_duplicatesList(itemsList)
{
    id = IdGenerator::getInstance()->getNextId();
}

DuplicateItemsGroup::DuplicateItemsGroup(const DuplicateItemsGroup& other)
    : m_duplicatesList(other.m_duplicatesList),
      id(other.id)
{

}

bool DuplicateItemsGroup::isEmpty() const {
    return m_duplicatesList.isEmpty();
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

qint64 DuplicateItemsGroup::getId() const {
    return id;
}

int DuplicateItemsGroup::getGroupSize() const {
    return m_duplicatesList.size();
}

QList<DuplicateItem> DuplicateItemsGroup::getDuplicateItemsList() const {
    return m_duplicatesList;
}
