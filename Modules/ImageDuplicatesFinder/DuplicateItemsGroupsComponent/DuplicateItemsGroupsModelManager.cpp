#include "DuplicateItemsGroupsModelManager.h"



DuplicateItemsGroupsModelManager::DuplicateItemsGroupsModelManager(DuplicateItemsGroupsModel* duplicateGroupsModel)
    : m_duplicateGroupsModel(duplicateGroupsModel)
{
    m_idfServiceController = IDFServiceController::getInstance();

    connect(m_idfServiceController, SIGNAL(serviceFinished()), this, SLOT(onServiceFinished()));
    connect(m_idfServiceController, SIGNAL(duplciateItemRemoved(qint64, qint64)), this, SLOT(onDuplicateItemRemoved(qint64, qint64)));
}

void DuplicateItemsGroupsModelManager::clearModel() {
    m_duplicateGroupsModel->clear();
}

void DuplicateItemsGroupsModelManager::onServiceFinished() {
    m_duplicateGroupsModel->fillModel(m_idfServiceController->getDuplicateItemsGroups());
}

void DuplicateItemsGroupsModelManager::onDuplicateItemRemoved(qint64 groupId, qint64 itemId) {
    // Обновляем соответсвующую группу в модели.
    m_duplicateGroupsModel->updateGroup(m_idfServiceController->getDuplicateItemGroup(groupId));
}
