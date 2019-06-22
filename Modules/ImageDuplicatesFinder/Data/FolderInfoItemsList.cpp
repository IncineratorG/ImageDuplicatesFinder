#include "FolderInfoItemsList.h"
#include "IdGenerator.h"
#include <QFileInfo>



FolderInfoItemsList::FolderInfoItemsList() {
    m_id = IdGenerator::getInstance()->getNextId();
}

FolderInfoItemsList::FolderInfoItemsList(const FolderInfoItemsList& other)
    : m_folderInfoItemsPathsMap(other.m_folderInfoItemsPathsMap),
      m_id(other.m_id)
{

}

void FolderInfoItemsList::clear() {
    m_folderInfoItemsPathsMap.clear();
}

void FolderInfoItemsList::appendDuplicateItem(const DuplicateItem& duplicateItem) {
    QFileInfo fileInfo(duplicateItem.getImagePath());
    const QString& duplicateItemFolderPath = fileInfo.absolutePath();

    FolderInfoItem folderInfoItem;
    if (m_folderInfoItemsPathsMap.contains(duplicateItemFolderPath)) {
        folderInfoItem = m_folderInfoItemsPathsMap.value(duplicateItemFolderPath);
    } else {
        FolderInfoItem newFolderInfoItem(duplicateItemFolderPath);
        folderInfoItem = newFolderInfoItem;
    }

    folderInfoItem.appendDuplicateItem(duplicateItem);

    m_folderInfoItemsPathsMap.insert(duplicateItemFolderPath, folderInfoItem);
}

QList<FolderInfoItem> FolderInfoItemsList::getFoldersInfosList() const {
    return m_folderInfoItemsPathsMap.values();
}
