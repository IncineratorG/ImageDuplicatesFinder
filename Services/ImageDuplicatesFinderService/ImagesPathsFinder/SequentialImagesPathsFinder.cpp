#include "SequentialImagesPathsFinder.h"
#include <QThread>
#include <QDebug>
#include <QDir>



SequentialImagesPathsFinder::SequentialImagesPathsFinder() {

}

void SequentialImagesPathsFinder::setPaths(std::shared_ptr<Paths> paths) {
    m_paths = paths;
}

std::shared_ptr<ImagesPaths> SequentialImagesPathsFinder::getImagesPaths() {
    if (m_imagesPaths == nullptr) {
        m_imagesPaths = std::shared_ptr<ImagesPaths>(new ImagesPaths());
    }

    return m_imagesPaths;
}

void SequentialImagesPathsFinder::run() {
    if (m_imagesPaths == nullptr) {
        m_imagesPaths = std::shared_ptr<ImagesPaths>(new ImagesPaths());
    } else {
        m_imagesPaths->clear();
    }

    if (m_paths == nullptr)
        return;

    doWork();
}

void SequentialImagesPathsFinder::doWork() {
    const QList<Path>& pathsList = m_paths->getPaths();
    for (int i = 0; i < pathsList.size(); ++i) {
        if (QThread::currentThread()->isInterruptionRequested()) {
            break;
        }

        const Path& path = pathsList.at(i);

        QDir directory(path.toString());
        const QFileInfoList& directoryInfoList = directory.entryInfoList(QDir::NoDotAndDotDot | QDir::Files);

        for (int j = 0; j < directoryInfoList.size(); ++j) {
            const QFileInfo& fileInfo = directoryInfoList.at(j);

            if (fileInfo.isHidden()) {
                continue;
            } else if (fileInfo.isDir()) {
                continue;
            } else {
                if (isImage(fileInfo.absoluteFilePath())) {
                    m_imagesPaths->appendImagePath(ImagePath(fileInfo.absoluteFilePath()));
                }
            }
        }
    }
}

bool SequentialImagesPathsFinder::isImage(const Path& path) const {
    const QString& pathString = path.toString();

    if (pathString.endsWith(".jpg", Qt::CaseInsensitive) ||
        pathString.endsWith(".jpeg", Qt::CaseInsensitive))
    {
        return true;
    } else {
        return false;
    }
}

bool SequentialImagesPathsFinder::isImage(const QString& path) const {
    if (path.endsWith(".jpg", Qt::CaseInsensitive) ||
        path.endsWith(".jpeg", Qt::CaseInsensitive))
    {
        return true;
    } else {
        return false;
    }
}


//void SequentialImagesPathsFinder::doWork() {
//    int counter = 0;

//    while (counter < 5) {
//        if (QThread::currentThread()->isInterruptionRequested())
//            break;

//        qDebug() << __PRETTY_FUNCTION__ << "->WORKING";

//        QThread::sleep(1);

//        ++counter;
//    }
//}
