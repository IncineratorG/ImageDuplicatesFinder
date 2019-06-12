#ifndef DUPLICATEITEMGROUPMODELMANAGER_H
#define DUPLICATEITEMGROUPMODELMANAGER_H

#include <QObject>
#include <QFileSystemWatcher>
#include "DuplicateItemGroupModel.h"
#include "../ServiceMediatorLayer/IDFServiceController.h"



class DuplicateItemGroupModelManager : public QObject
{
    Q_OBJECT

public:
    DuplicateItemGroupModelManager(DuplicateItemGroupModel* duplicateGroupModel);

public slots:
    void loadDuplicateGroup(const int groupId);

    void setGeneralImageItem(const qint64 itemId);

    void openItemPath(const qint64 itemId);

    void markItemAsNotDuplicate(const qint64 itemId);

    void removeItemFromDisk(const qint64 itemId);

    void stopListenToFileChangies();

    QString getItemImagePath(const qint64 itemId) const;
    QString getItemImagePathText(const qint64 itemId) const;

private slots:
    void onFileChanged(const QString& path);
    void onDuplicateItemRemoved(qint64 groupId, qint64 itemId);

private:
    DuplicateItemGroupModel* m_duplicateGroupModel;
    IDFServiceController* m_idfServiceController;

    QFileSystemWatcher m_fileSystemWatcher;

    void disconnectFileWatcher();
};

#endif // DUPLICATEITEMGROUPMODELMANAGER_H
