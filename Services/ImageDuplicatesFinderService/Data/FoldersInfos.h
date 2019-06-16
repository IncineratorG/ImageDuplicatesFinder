#ifndef FOLDERSINFOS_H
#define FOLDERSINFOS_H

#include "FolderInfo.h"
#include <QList>



class FoldersInfos
{
public:
    FoldersInfos();

    void appendFilePath(const QString& filePath);

    QList<FolderInfo> getFoldersInfosList() const;

private:
    QList<FolderInfo> m_folderInfosList;
};

#endif // FOLDERSINFOS_H
