#include "DuplicateItemsGroupsModelManager.h"



DuplicateItemsGroupsModelManager::DuplicateItemsGroupsModelManager(DuplicateItemsGroupsModel* duplicateGroupsModel)
    : m_duplicateGroupsModel(duplicateGroupsModel)
{
    m_idfServiceController = IDFServiceController::getInstance();

    connect(m_idfServiceController, SIGNAL(serviceFinished()), this, SLOT(onServiceFinished()));
}

void DuplicateItemsGroupsModelManager::clearModel() {
    m_duplicateGroupsModel->clear();
}

void DuplicateItemsGroupsModelManager::onServiceFinished() {
    m_duplicateGroupsModel->fillModel(m_idfServiceController->getDuplicateItemsGroups());
}
