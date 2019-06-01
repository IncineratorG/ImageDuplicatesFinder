#include "DuplicateItemGroupModelManager.h"
#include <QDebug>



DuplicateItemGroupModelManager::DuplicateItemGroupModelManager(DuplicateItemGroupModel* duplicateGroupModel)
    : m_duplicateGroupModel(duplicateGroupModel)
{
    m_idfServiceController = IDFServiceController::getInstance();
}

void DuplicateItemGroupModelManager::loadDuplicateGroup(const int groupId) {
    qDebug() << __PRETTY_FUNCTION__ << "->GROUP_ID: " << groupId;
}
