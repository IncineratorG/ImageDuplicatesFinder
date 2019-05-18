#include "DuplicateImagesListModelManager.h"
#include <QDebug>



DuplicateImagesListModelManager::DuplicateImagesListModelManager() {
    connect(&idfService, SIGNAL(started()), this, SLOT(onImageDuplicatesFinderServiceStarted()));
    connect(&idfService, SIGNAL(interrupted()), this, SLOT(onImageDuplicatesFinderServiceInterrupted()));
    connect(&idfService, SIGNAL(finished()), this, SLOT(onImageDuplicatesFinderServiceFinished()));
}

void DuplicateImagesListModelManager::start() {
    qDebug() << __PRETTY_FUNCTION__;

    const QString path_1 = "C:/Users/Alexander/Downloads/TEST_IMAGES";

    IDFServiceInputData inputData;
    inputData.appendInputDataItem(IDFServiceInputDataItem(path_1));

    idfService.start(inputData);
}

void DuplicateImagesListModelManager::stop() {
    qDebug() << __PRETTY_FUNCTION__;

    idfService.stop();
}

void DuplicateImagesListModelManager::onImageDuplicatesFinderServiceStarted() {
    qDebug() << __PRETTY_FUNCTION__;
}

void DuplicateImagesListModelManager::onImageDuplicatesFinderServiceInterrupted() {
    qDebug() << __PRETTY_FUNCTION__;
}

void DuplicateImagesListModelManager::onImageDuplicatesFinderServiceFinished() {
    qDebug() << __PRETTY_FUNCTION__;

    IDFServiceOutputData outputData = idfService.getOutputData();


    // ===
    std::shared_ptr<ImagesDuplicatesGroups> imagesDuplicatesGroupsPtr = outputData.getDuplicatesGroups();
    QList<ImageDuplicatesGroup> duplicatesGroupsList = imagesDuplicatesGroupsPtr->getGroupsList();
    for (int i = 0; i < duplicatesGroupsList.size(); ++i) {
        const ImageDuplicatesGroup& group = duplicatesGroupsList.at(i);

        qDebug() << "";
        const QList<QString>& imagesPathsList = group.getImagesList();
        for (int j = 0; j < imagesPathsList.size(); ++j) {
            const QString& imagePath = imagesPathsList.at(j);

            qDebug() << imagePath << " - " << group.getSimilarityScore(imagePath);
        }
    }
    // ===
}
