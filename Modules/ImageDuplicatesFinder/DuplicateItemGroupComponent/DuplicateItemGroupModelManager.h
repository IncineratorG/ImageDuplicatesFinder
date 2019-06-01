#ifndef DUPLICATEITEMGROUPMODELMANAGER_H
#define DUPLICATEITEMGROUPMODELMANAGER_H

#include <QObject>
#include "DuplicateItemGroupModel.h"
#include "../ServiceMediatorLayer/IDFServiceController.h"



class DuplicateItemGroupModelManager : public QObject
{
    Q_OBJECT

public:
    DuplicateItemGroupModelManager(DuplicateItemGroupModel* duplicateGroupModel);

public slots:
    void loadDuplicateGroup(const int groupId);

    void openItemPath(const qint64 itemId);

private:
    DuplicateItemGroupModel* m_duplicateGroupModel;
    IDFServiceController* m_idfServiceController;
};

#endif // DUPLICATEITEMGROUPMODELMANAGER_H
