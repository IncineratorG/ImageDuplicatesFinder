#include "SequentialFoldersStatisticBuilder.h"
#include "../Data/FolderInfo.h"
#include <QSet>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>



SequentialFoldersStatisticBuilder::SequentialFoldersStatisticBuilder()
    : OPERATION_NAME("Построение статистики")
{

}

void SequentialFoldersStatisticBuilder::setImagesDuplicatesGroups(std::shared_ptr<ImagesDuplicatesGroups> imagesDuplicatesGroups) {
    m_imagesDuplicatesGroups = imagesDuplicatesGroups;
}

void SequentialFoldersStatisticBuilder::run() {
    if (m_imagesDuplicatesGroups == nullptr) {
        return;
    }

    doWork();
}

void SequentialFoldersStatisticBuilder::doWork() {
    // ===
    emit publishProgress(OperationProgress(OPERATION_NAME, 0));
    // ===




//    FolderInfo info;




//    QSet<QString> distinctImagesPathsSet;

//    const QList<ImageDuplicatesGroup>& duplicatesGroupsList = m_imagesDuplicatesGroups->getGroupsList();
//    for (int i = 0; i < duplicatesGroupsList.size(); ++i) {
//        const ImageDuplicatesGroup& group = duplicatesGroupsList.at(i);
//        const QList<QString>& groupImagesPathsList = group.getImagesList();

//        for (int j = 0; j < groupImagesPathsList.size(); ++j) {
//            const QString& imagePath = groupImagesPathsList.at(j);

//            QFileInfo imageFileInfo(imagePath);

//            distinctImagesPathsSet.insert(imageFileInfo.absolutePath());
//        }
//    }

//    const QList<QString>& distinctImagesPathsList = distinctImagesPathsSet.toList();
//    for (int i = 0; i < distinctImagesPathsList.size(); ++i) {
//        qDebug() << __PRETTY_FUNCTION__ << "->PATH: " << distinctImagesPathsList.at(i);
//    }
//    qDebug() << __PRETTY_FUNCTION__ << "->DISTINCT_IMAGES_PATHS_SIZE: " << distinctImagesPathsList.size();



    // ===
//    ImagePath
    // ===



    // ===
    emit publishProgress(OperationProgress(OPERATION_NAME, 100));
    // ===
}
