#include "FolderInfo.h"
#include <QFileInfo>
#include <QDir>



FolderInfo::FolderInfo() {

}

FolderInfo::FolderInfo(const QString& folderPath)
    : m_folderPath(folderPath)
{

}

FolderInfo::FolderInfo(const FolderInfo& other)
    : m_folderPath(other.m_folderPath)
{

}

QString FolderInfo::getFolderPath() const {
    return m_folderPath;
}

qint64 FolderInfo::getTotalFilesCount() const {
    QDir currentDirectory(m_folderPath);

    const QFileInfoList& directoryInfoList = currentDirectory.entryInfoList(QDir::NoDotAndDotDot | QDir::Files);

    return directoryInfoList.size();
}

qint64 FolderInfo::getTotalImagesCount() const {
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

qint64 FolderInfo::getDuplicateImagesCount() const {
    return m_duplicateImagesPaths.size();
}

qint64 FolderInfo::getSubfoldersCount() const {
    QDir currentDirectory(m_folderPath);

    const QFileInfoList& directoryInfoList = currentDirectory.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);

    return directoryInfoList.size();
}

bool FolderInfo::belongToFolder(const QString& filePath) const {
    QFileInfo fileInfo(filePath);

    return m_folderPath == fileInfo.absolutePath();
}

bool FolderInfo::appendDuplicateImageFilePath(const QString& imageFilePath) {
    QFileInfo fileInfo(imageFilePath);
    if (fileInfo.absolutePath() != m_folderPath) {
        return false;
    }

    m_duplicateImagesPaths.insert(imageFilePath);

    return true;
}

void FolderInfo::removeDuplicateImageFilePath(const QString& imageFilePath) {
    m_duplicateImagesPaths.remove(imageFilePath);
}

bool FolderInfo::containDuplicateImageFilePath(const QString& imageFilePath) const {
    return m_duplicateImagesPaths.contains(imageFilePath);
}

bool FolderInfo::isImage(const QString& filePath) const {
    if (filePath.endsWith(".jpg", Qt::CaseInsensitive) ||
        filePath.endsWith(".jpeg", Qt::CaseInsensitive))
    {
        return true;
    } else {
        return false;
    }
}
