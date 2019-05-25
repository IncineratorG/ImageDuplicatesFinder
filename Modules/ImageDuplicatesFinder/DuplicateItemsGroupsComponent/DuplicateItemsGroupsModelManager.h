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

private:
    DuplicateItemsGroupsModel* m_duplicateGroupsModel;
    IDFServiceController* m_idfServiceController;
};

#endif // DUPLICATEITEMSGROUPSMODELMANAGER_H
