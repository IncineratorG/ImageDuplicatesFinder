#include "DuplicateItemsListModelManager.h"
#include <QDebug>



DuplicateItemsListModelManager::DuplicateItemsListModelManager(DuplicateItemsListModel* duplicateItemsListModel)
    : m_duplicateItemsListModel(duplicateItemsListModel)
{
    m_idfServiceController = IDFServiceController::getInstance();

    connect(m_idfServiceController, SIGNAL(serviceStarted()), this, SLOT(onServiceStarted()));
    connect(m_idfServiceController, SIGNAL(serviceInterrupted()), this, SLOT(onServiceInterrupted()));
    connect(m_idfServiceController, SIGNAL(serviceFinished()), this, SLOT(onServiceFinished()));
}

void DuplicateItemsListModelManager::onServiceStarted() {
    qDebug() << __PRETTY_FUNCTION__;
}

void DuplicateItemsListModelManager::onServiceInterrupted() {
    qDebug() << __PRETTY_FUNCTION__;
}

void DuplicateItemsListModelManager::onServiceFinished() {
    qDebug() << __PRETTY_FUNCTION__;

    //    // ===
    //    std::shared_ptr<ImagesDuplicatesGroups> imagesDuplicatesGroupsPtr = outputData.getDuplicatesGroups();
    //    QList<ImageDuplicatesGroup> duplicatesGroupsList = imagesDuplicatesGroupsPtr->getGroupsList();
    //    for (int i = 0; i < duplicatesGroupsList.size(); ++i) {
    //        const ImageDuplicatesGroup& group = duplicatesGroupsList.at(i);

    //        qDebug() << "";
    //        const QList<QString>& imagesPathsList = group.getImagesList();
    //        for (int j = 0; j < imagesPathsList.size(); ++j) {
    //            const QString& imagePath = imagesPathsList.at(j);

    //            qDebug() << imagePath << " - " << group.getSimilarityScore(imagePath);
    //        }
    //    }
    //    // ===
}
