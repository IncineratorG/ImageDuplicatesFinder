#ifndef DUPLICATEITEMSGROUPSMODELMANAGER_H
#define DUPLICATEITEMSGROUPSMODELMANAGER_H

#include <QObject>
#include "DuplicateItemsGroupsModel.h"
#include "../ServiceMediatorLayer/IDFServiceController.h"



class DuplicateItemsGroupsModelManager : public QObject
{
    Q_OBJECT

public:
    DuplicateItemsGroupsModelManager(DuplicateItemsGroupsModel* duplicateGroupsModel);

public slots:
    void clearModel();

private slots:
    void onServiceFinished();
    void onDuplicateItemRemoved(qint64 groupId, qint64 itemId);

private:
    DuplicateItemsGroupsModel* m_duplicateGroupsModel;
    IDFServiceController* m_idfServiceController;
};

#endif // DUPLICATEITEMSGROUPSMODELMANAGER_H
