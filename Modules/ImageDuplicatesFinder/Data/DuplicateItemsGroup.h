#ifndef DUPLICATEITEMSGROUP_H
#define DUPLICATEITEMSGROUP_H

#include <QList>
#include "DuplicateItem.h"



class DuplicateItemsGroup
{
public:
    DuplicateItemsGroup();
    DuplicateItemsGroup(const QList<DuplicateItem>& itemsList);
    DuplicateItemsGroup(const DuplicateItemsGroup& other);

    bool isEmpty() const;

    void clear();

    void appendDuplicate(const DuplicateItem& item);
    void removeDuplicate(const DuplicateItem& item);
    void removeDuplicateAtPosition(const int position);

    int getGroupSize() const;

    QList<DuplicateItem> getDuplicateItemsList() const;

private:
    QList<DuplicateItem> m_duplicatesList;
};

#endif // DUPLICATEITEMSGROUP_H
