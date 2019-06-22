#ifndef FOLDERINFOITEM_H
#define FOLDERINFOITEM_H

#include <QString>
#include <QSet>
#include "DuplicateItem.h"



class FolderInfoItem
{
public:
    FolderInfoItem();
    FolderInfoItem(const QString& folderPath);
    FolderInfoItem(const FolderInfoItem& other);

    QString getFolderPath() const;

    qint64 getTotalFilesCount() const;
    qint64 getTotalImagesCount() const;
    qint64 getDuplicateImagesCount() const;
    qint64 getSubfoldersCount() const;

    bool appendDuplicateItem(const DuplicateItem& duplicateItem);
    bool removeDuplicateItem(const qint64 duplicateItemId);

    bool containDuplicateItem(const DuplicateItem& duplicateItem) const;
    bool containDuplicateItemWithId(const qint64 duplicateItemId) const;
    bool containDuplicateItemWithImagePath(const QString& imagePath) const;

private:
    QString m_folderPath;

    qint64 m_id;

    QSet<qint64> m_duplicateItemsIds;
    QSet<QString> m_duplicateItemsPaths;
    QList<DuplicateItem> m_duplicateItemsList;


    bool isImage(const QString& filePath) const;
};

#endif // FOLDERINFOITEM_H
