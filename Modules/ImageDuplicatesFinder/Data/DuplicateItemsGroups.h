#ifndef DUPLICATEITEMSGROUPS_H
#define DUPLICATEITEMSGROUPS_H

#include "DuplicateItemsGroup.h"



class DuplicateItemsGroups
{
public:
    DuplicateItemsGroups();
    DuplicateItemsGroups(const QList<DuplicateItemsGroup>& groupsList);
    DuplicateItemsGroups(const DuplicateItemsGroups& other);

    void clear();

    void appendGroup(const DuplicateItemsGroup& group);
    bool removeGroupAtPosition(const int position);

    QList<DuplicateItemsGroup> getGroupsList() const;

private:
    QList<DuplicateItemsGroup> m_groupsList;
};

#endif // DUPLICATEITEMSGROUPS_H
