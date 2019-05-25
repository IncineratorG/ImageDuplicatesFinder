#include "SequetialInputPathsPreparator.h"



SequetialInputPathsPreparator::SequetialInputPathsPreparator() {

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
    m_inputPaths = m_serviceInputData.toPaths();
}
