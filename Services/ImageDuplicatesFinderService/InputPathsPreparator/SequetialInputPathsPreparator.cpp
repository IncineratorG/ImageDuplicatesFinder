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

QString SequetialInputPathsPreparator::getOperationName() {
    return OPERATION_NAME;
}

void SequetialInputPathsPreparator::run() {
    doWork();
}

void SequetialInputPathsPreparator::doWork() {
    m_inputPaths = m_serviceInputData.toPaths();
}
