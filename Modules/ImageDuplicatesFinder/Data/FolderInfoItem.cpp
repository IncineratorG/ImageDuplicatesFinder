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
      m_duplicateItemsIds(other.m_duplicateItemsIds),
      m_duplicateItemsPaths(other.m_duplicateItemsPaths)
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

    qint64 filesCount = 0;

    for (int i = 0; i < directoryInfoList.size(); ++i) {
        const QFileInfo& fileInfo = directoryInfoList.at(i);
        if (isImage(fileInfo.absoluteFilePath())) {
            ++filesCount;
        }
    }

    return filesCount;
}

qint64 FolderInfoItem::getDuplicateImagesCount() const {
    return m_duplicateItemsIds.size();
}

qint64 FolderInfoItem::getSubfoldersCount() const {
    QDir currentDirectory(m_folderPath);

    const QFileInfoList& directoryInfoList = currentDirectory.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);

    return directoryInfoList.size();
}

bool FolderInfoItem::appendDuplicateItem(const DuplicateItem& duplicateItem) {
    if (m_duplicateItemsIds.contains(duplicateItem.getId())) {
        return false;
    }

    m_duplicateItemsIds.insert(duplicateItem.getId());
    m_duplicateItemsPaths.insert(duplicateItem.getImagePath());
    m_duplicateItemsList.append(duplicateItem);

    return true;
}

bool FolderInfoItem::removeDuplicateItem(const qint64 duplicateItemId) {
    if (m_duplicateItemsIds.contains(duplicateItemId)) {
        return false;
    }

    for (int i = 0; i < m_duplicateItemsList.size(); ++i) {
        const DuplicateItem& duplicateItem = m_duplicateItemsList.at(i);

        if (duplicateItem.getId() == duplicateItemId) {

        }
    }

    return false;
}

bool FolderInfoItem::containDuplicateItemWithId(const qint64 duplicateItemId) const {
    return false;
}

bool FolderInfoItem::containDuplicateItemWithImagePath(const QString& imagePath) const {
    return false;
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
