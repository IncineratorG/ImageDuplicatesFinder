#ifndef FOLDERINFO_H
#define FOLDERINFO_H

#include <QString>
#include <QSet>



class FolderInfo
{
public:
    FolderInfo();
    FolderInfo(const QString& folderPath);
    FolderInfo(const FolderInfo& other);

    QString getFolderPath() const;

    qint64 getTotalFilesCount() const;
    qint64 getTotalImagesCount() const;
    qint64 getDuplicateImagesCount() const;
    qint64 getSubfoldersCount() const;

    bool belongToFolder(const QString& filePath) const;

    bool appendDuplicateImageFilePath(const QString& imageFilePath);
    void removeDuplicateImageFilePath(const QString& imageFilePath);
    bool containDuplicateImageFilePath(const QString& imageFilePath) const;

    bool operator==(const FolderInfo& other) {
        return this->m_folderPath == other.m_folderPath;
    }

private:
    QString m_folderPath;

    QSet<QString> m_duplicateImagesPaths;


    bool isImage(const QString& filePath) const;
};

#endif // FOLDERINFO_H
