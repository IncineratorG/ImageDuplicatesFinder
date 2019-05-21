#ifndef DUPLICATEITEMSLISTMODELMANAGER_H
#define DUPLICATEITEMSLISTMODELMANAGER_H

#include <QObject>
#include "DuplicateItemsListModel.h"
#include "../ServiceMediatorLayer/IDFServiceController.h"



class DuplicateItemsListModelManager : public QObject
{
    Q_OBJECT

public:
    DuplicateItemsListModelManager(DuplicateItemsListModel* duplicateItemsListModel);

private slots:
    void onServiceStarted();
    void onServiceInterrupted();
    void onServiceFinished();

private:
    DuplicateItemsListModel* m_duplicateItemsListModel;
    IDFServiceController* m_idfServiceController;
};

#endif // DUPLICATEITEMSLISTMODELMANAGER_H
