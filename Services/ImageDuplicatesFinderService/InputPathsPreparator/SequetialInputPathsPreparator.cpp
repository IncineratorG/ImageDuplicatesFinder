#include "SequetialInputPathsPreparator.h"



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

    m_inputPaths = m_serviceInputData.toPaths();

    // ===
    emit publishProgress(OperationProgress(OPERATION_NAME, 100));
    // ===
}
