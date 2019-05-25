#include "SequentialImagesHistogramsBuilder.h"
#include <QThread>
#include <QDebug>



SequentialImagesHistogramsBuilder::SequentialImagesHistogramsBuilder()
    : OPERATION_NAME("Построение гистограмм")
{

}

void SequentialImagesHistogramsBuilder::setImagesPaths(std::shared_ptr<ImagesPaths> imagesPaths) {
    m_imagesPaths = imagesPaths;
}

std::shared_ptr<ImagesHistograms> SequentialImagesHistogramsBuilder::getImagesHistograms() {
    if (m_histograms == nullptr) {
        m_histograms = std::shared_ptr<ImagesHistograms>(new ImagesHistograms());
    }

    return m_histograms;
}

QString SequentialImagesHistogramsBuilder::getOperationName() {
    return OPERATION_NAME;
}

void SequentialImagesHistogramsBuilder::run() {
    if (m_histograms == nullptr) {
        m_histograms = std::shared_ptr<ImagesHistograms>(new ImagesHistograms());
    } else {
        m_histograms->clear();
    }

    if (m_imagesPaths == nullptr)
        return;

    doWork();
}

void SequentialImagesHistogramsBuilder::doWork() {
    const QList<ImagePath>& imagesPaths = m_imagesPaths->getPaths();
    for (int i = 0; i < imagesPaths.size(); ++i) {
        if (QThread::currentThread()->isInterruptionRequested())
            break;

        const ImagePath& currentImagePath = imagesPaths.at(i);

        m_histograms->appendImageHistogram(ImageHistogram(currentImagePath.toString()));
    }
}












//void SequentialImagesHistogramsBuilder::doWork() {
//    int count = 0;
//    while (count < 5) {
//        if (QThread::currentThread()->isInterruptionRequested()) {
//            break;
//        }

//        qDebug() << __PRETTY_FUNCTION__ << "->WORKING";

//        QThread::sleep(1);

//        ++count;
//    }
//}
