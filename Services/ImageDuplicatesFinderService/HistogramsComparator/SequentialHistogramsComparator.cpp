#include "SequentialHistogramsComparator.h"
#include <QThread>
#include <QDebug>



SequentialHistogramsComparator::SequentialHistogramsComparator()
    : CRITICAL_SIMILARITY_SCORE(0.8f),
      OPERATION_NAME("Сопоставление гистограмм")
{

}

void SequentialHistogramsComparator::setImagesHistograms(std::shared_ptr<ImagesHistograms> histograms) {
    m_histograms = histograms;
}

std::shared_ptr<ImagesDuplicatesGroups> SequentialHistogramsComparator::getImagesDuplicates() {
    if (m_duplicatesGroups == nullptr) {
        m_duplicatesGroups = std::shared_ptr<ImagesDuplicatesGroups>(new ImagesDuplicatesGroups());
    }

    return m_duplicatesGroups;
}

QString SequentialHistogramsComparator::getOperationName() {
    return OPERATION_NAME;
}

void SequentialHistogramsComparator::run() {
    if (m_duplicatesGroups == nullptr) {
        m_duplicatesGroups = std::shared_ptr<ImagesDuplicatesGroups>(new ImagesDuplicatesGroups());
    } else {
        m_duplicatesGroups->clear();
    }

    if (m_histograms == nullptr) {
        return;
    }

    doWork();
}

void SequentialHistogramsComparator::doWork() {
    QSet<QString> processedImagesPathsSet;

    float currentCriticalSimilarityScore = CRITICAL_SIMILARITY_SCORE;

    const QList<ImageHistogram>& histogramsList = m_histograms->getHistograms();
    for (int i = 0; i < histogramsList.size(); ++i) {
        if (QThread::currentThread()->isInterruptionRequested()) {
            break;
        }

        const ImageHistogram& currentHistogram = histogramsList.at(i);
        if (processedImagesPathsSet.contains(currentHistogram.getImagePath())) {
            continue;
        }

        ImageDuplicatesGroup currentImageDuplicatesGroup;
        currentImageDuplicatesGroup.appendImage(currentHistogram.getImagePath(), 1.0f);

        for (int j = i + 1; j < histogramsList.size(); ++j) {
            const ImageHistogram& otherHistogram = histogramsList.at(j);
            if (processedImagesPathsSet.contains(otherHistogram.getImagePath())) {
                continue;
            }

            float similarityScore = currentHistogram.similarityScore(otherHistogram);
            if (similarityScore < currentCriticalSimilarityScore) {
                continue;
            }

            currentImageDuplicatesGroup.appendImage(otherHistogram.getImagePath(), similarityScore);

            processedImagesPathsSet.insert(otherHistogram.getImagePath());
        }

        if (currentImageDuplicatesGroup.getDuplicatesListSise() > 1) {
            m_duplicatesGroups->appendGroup(currentImageDuplicatesGroup);
        }
    }
}



//void SequentialHistogramsComparator::doWork() {
//    int counter = 0;

//    while (counter < 5) {
//        if (QThread::currentThread()->isInterruptionRequested())
//            break;

//        qDebug() << __PRETTY_FUNCTION__ << "->WORKING";

//        QThread::sleep(1);

//        ++counter;
//    }
//}
