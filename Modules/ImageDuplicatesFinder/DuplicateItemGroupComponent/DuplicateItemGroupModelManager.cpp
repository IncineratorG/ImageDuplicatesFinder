#include "DuplicateItemGroupModelManager.h"
#include <QDebug>



DuplicateItemGroupModelManager::DuplicateItemGroupModelManager(DuplicateItemGroupModel* duplicateGroupModel)
    : m_duplicateGroupModel(duplicateGroupModel)
{
    m_idfServiceController = IDFServiceController::getInstance();
}

void DuplicateItemGroupModelManager::loadDuplicateGroup(const int groupId) {
    const DuplicateItemsGroup& group = m_idfServiceController->getDuplicateItemGroup(groupId);

    m_duplicateGroupModel->fillModel(group);
}

void DuplicateItemGroupModelManager::openItemPath(const qint64 itemId) {
    auto modelIndexesList = m_duplicateGroupModel->match(
                                        m_duplicateGroupModel->index(0, 0),
                                        DuplicateItemGroupModel::IDRole,
                                        itemId);
    if (modelIndexesList.size() <= 0) {
        return;
    }

    const QModelIndex& matchedItemIndex = modelIndexesList.at(0);

    const QString& itemPath = m_duplicateGroupModel->data(matchedItemIndex, DuplicateItemGroupModel::DuplicateImagePathRole).toString();
}
