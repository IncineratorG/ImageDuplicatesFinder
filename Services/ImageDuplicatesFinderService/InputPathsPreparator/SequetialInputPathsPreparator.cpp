#include "SequetialInputPathsPreparator.h"
#include <QDebug>



SequetialInputPathsPreparator::SequetialInputPathsPreparator()
    : OPERATION_NAME("Подготовка данных")
{

}

void SequetialInputPathsPreparator::setInputData(IDFServiceInputData inputData) {
    m_serviceInputData = inputData;
}

Paths SequetialInputPathsPreparator::getPaths() {
    return m_inputPaths;
}

void SequetialInputPathsPreparator::run() {
    doWork();
}

void SequetialInputPathsPreparator::doWork() {
    // ===
    emit publishProgress(OperationProgress(OPERATION_NAME, 0));
    // ===

    m_inputPaths.clear();

    const QList<IDFServiceInputDataItem>& inputItemsList = m_serviceInputData.getInputDataList();
    for (int i = 0; i < inputItemsList.size(); ++i) {
        const IDFServiceInputDataItem& item = inputItemsList.at(i);

        const QString pathString = item.getPath();
        const bool processSubpath = item.getProcessSubpath();

        // ===
//        qDebug() << __PRETTY_FUNCTION__ << "->PATH: " << pathString << " - " << processSubpath;
        // ===

        if (!processSubpath) {
            m_inputPaths.appendPath(Path(pathString));

            // ===
            int progress = ((float) i / inputItemsList.size()) * 100;
            emit publishProgress(OperationProgress(OPERATION_NAME, progress));
            // ===

            continue;
        }

        toPaths_r(QDir(pathString), m_inputPaths);

        // ===
        int progress = ((float) i / inputItemsList.size()) * 100;
        emit publishProgress(OperationProgress(OPERATION_NAME, progress));
        // ===
    }

    // ===
    emit publishProgress(OperationProgress(OPERATION_NAME, 100));
    // ===
}

void SequetialInputPathsPreparator::toPaths_r(const QDir& directory, Paths& paths) {
    paths.appendPath(Path(directory.absolutePath()));

    if (QThread::currentThread()->isInterruptionRequested()) {
        return;
    }

    const QFileInfoList& directoryInfoList = directory.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Dirs);
    for (int i = 0; i < directoryInfoList.size(); ++i) {
        const QFileInfo& fileInfo = directoryInfoList.at(i);

        if (fileInfo.isHidden()) {
            continue;
        }

        if (fileInfo.isDir()) {
            toPaths_r(QDir(fileInfo.absoluteFilePath()), paths);
        }
    }
}

//void SequetialInputPathsPreparator::doWork() {
//    // ===
//    emit publishProgress(OperationProgress(OPERATION_NAME, 0));
//    // ===

//    m_inputPaths = m_serviceInputData.toPaths();

//    // ===
//    emit publishProgress(OperationProgress(OPERATION_NAME, 100));
//    // ===
//}
