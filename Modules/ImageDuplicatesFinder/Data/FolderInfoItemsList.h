#ifndef FOLDERINFOITEMSLIST_H
#define FOLDERINFOITEMSLIST_H

#include <QMap>
#include "FolderInfoItem.h"
#include "DuplicateItem.h"



class FolderInfoItemsList
{
public:
    FolderInfoItemsList();
    FolderInfoItemsList(const FolderInfoItemsList& other);

    void clear();

    void appendDuplicateItem(const DuplicateItem& duplicateItem);

    QList<FolderInfoItem> getFoldersInfosList() const;

private:
    QMap<QString, FolderInfoItem> m_folderInfoItemsPathsMap;

    qint64 m_id;
};

#endif // FOLDERINFOITEMSLIST_H
