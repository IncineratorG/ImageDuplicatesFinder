#include "FolderInfoItem.h"
#include "IdGenerator.h"
#include <QFileInfo>
#include <QDir>



FolderInfoItem::FolderInfoItem() {
    m_id = IdGenerator::getInstance()->getNextId();
}

FolderInfoItem::FolderInfoItem(const QString& folderPath)
    : m_folderPath(folderPath)
{
    m_id = IdGenerator::getInstance()->getNextId();
}

FolderInfoItem::FolderInfoItem(const FolderInfoItem& other)
    : m_folderPath(other.m_folderPath),
      m_id(other.m_id),
      m_duplicateItemsIdsMap(other.m_duplicateItemsIdsMap),
      m_duplicateItemsPathsMap(other.m_duplicateItemsPathsMap)
{

}

QString FolderInfoItem::getFolderPath() const {
    return m_folderPath;
}

qint64 FolderInfoItem::getTotalFilesCount() const {
    QDir currentDirectory(m_folderPath);

    const QFileInfoList& directoryInfoList = currentDirectory.entryInfoList(QDir::NoDotAndDotDot | QDir::Files);

    return directoryInfoList.size();
}

qint64 FolderInfoItem::getTotalImagesCount() const {
    QDir currentDirectory(m_folderPath);

    const QFileInfoList& directoryInfoList = currentDirectory.entryInfoList(QDir::NoDotAndDotDot | QDir::Files);

    qint64 imageFilesCount = 0;

    for (int i = 0; i < directoryInfoList.size(); ++i) {
        const QFileInfo& fileInfo = directoryInfoList.at(i);
        if (isImage(fileInfo.absoluteFilePath())) {
            ++imageFilesCount;
        }
    }

    return imageFilesCount;
}

qint64 FolderInfoItem::getDuplicateImagesCount() const {
    return m_duplicateItemsIdsMap.size();
}

qint64 FolderInfoItem::getSubfoldersCount() const {
    QDir currentDirectory(m_folderPath);

    const QFileInfoList& directoryInfoList = currentDirectory.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);

    return directoryInfoList.size();
}

bool FolderInfoItem::appendDuplicateItem(const DuplicateItem& duplicateItem) {
    if (m_duplicateItemsIdsMap.contains(duplicateItem.getId())) {
        return false;
    }

    m_duplicateItemsIdsMap.insert(duplicateItem.getId(), duplicateItem);
    m_duplicateItemsPathsMap.insert(duplicateItem.getImagePath(), duplicateItem);

    return true;
}

bool FolderInfoItem::removeDuplicateItem(const qint64 duplicateItemId) {
    if (!m_duplicateItemsIdsMap.contains(duplicateItemId)) {
        return false;
    }

    const DuplicateItem duplicateItem = m_duplicateItemsIdsMap.take(duplicateItemId);
    m_duplicateItemsPathsMap.remove(duplicateItem.getImagePath());

    return false;
}

bool FolderInfoItem::containDuplicateItemWithId(const qint64 duplicateItemId) const {
    return m_duplicateItemsIdsMap.contains(duplicateItemId);
}

bool FolderInfoItem::containDuplicateItemWithImagePath(const QString& imagePath) const {
    return m_duplicateItemsPathsMap.contains(imagePath);
}

bool FolderInfoItem::isImage(const QString& filePath) const {
    if (filePath.endsWith(".jpg", Qt::CaseInsensitive) ||
        filePath.endsWith(".jpeg", Qt::CaseInsensitive))
    {
        return true;
    } else {
        return false;
    }
}
