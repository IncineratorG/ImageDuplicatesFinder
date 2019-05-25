#include "DuplicateItemsGroupsModelManager.h"



DuplicateItemsGroupsModelManager::DuplicateItemsGroupsModelManager(DuplicateItemsGroupsModel* duplicateGroupsModel)
    : m_duplicateGroupsModel(duplicateGroupsModel)
{
    m_idfServiceController = IDFServiceController::getInstance();
}
