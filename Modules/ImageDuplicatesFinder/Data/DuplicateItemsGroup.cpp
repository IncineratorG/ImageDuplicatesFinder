#include "DuplicateItemsGroup.h"



DuplicateItemsGroup::DuplicateItemsGroup() {

}

DuplicateItemsGroup::DuplicateItemsGroup(const QList<DuplicateItem>& itemsList)
    : m_duplicatesList(itemsList)
{

}

DuplicateItemsGroup::DuplicateItemsGroup(const DuplicateItemsGroup& other)
    : m_duplicatesList(other.m_duplicatesList)
{

}

bool DuplicateItemsGroup::isEmpty() const {
    return m_duplicatesList.isEmpty();
}

void DuplicateItemsGroup::clear() {
    m_duplicatesList.clear();
}

int DuplicateItemsGroup::getGroupSize() const {
    return m_duplicatesList.size();
}

QList<DuplicateItem> DuplicateItemsGroup::getDuplicateItemsList() const {
    return m_duplicatesList;
}
