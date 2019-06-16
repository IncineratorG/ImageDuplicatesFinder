#include "FoldersInfos.h"
#include <QFileInfo>



FoldersInfos::FoldersInfos() {

}

void FoldersInfos::appendFilePath(const QString& filePath) {
    QFileInfo fileInfo(filePath);
    const QString& fileFolder = fileInfo.absolutePath();

    bool folderInfoExist = false;
    for (int i = 0; i < m_folderInfosList.size(); ++i) {
        if (m_folderInfosList.at(i).getFolderPath() == fileFolder) {
            FolderInfo& folderInfo = m_folderInfosList[i];

            folderInfo.appendDuplicateImageFilePath(filePath);

            folderInfoExist = true;
        }
    }

    if (folderInfoExist) {
        return;
    }

    FolderInfo newFolderInfo(fileFolder);
    newFolderInfo.appendDuplicateImageFilePath(filePath);

    m_folderInfosList.append(newFolderInfo);
}

QList<FolderInfo> FoldersInfos::getFoldersInfosList() const {
    return m_folderInfosList;
}
