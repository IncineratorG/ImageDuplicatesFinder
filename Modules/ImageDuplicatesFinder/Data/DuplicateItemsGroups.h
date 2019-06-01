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

    qint64 getId() const;

    QList<DuplicateItemsGroup> getGroupsList() const;

private:
    QList<DuplicateItemsGroup> m_groupsList;

    qint64 id;
};

#endif // DUPLICATEITEMSGROUPS_H
