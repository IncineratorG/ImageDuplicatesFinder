#include "IDFStore.h"



IDFStore::IDFStore() {

}

void IDFStore::setInputData(const IDFServiceInputData& inputData) {
    m_serviceInputData = inputData;
    emit inputDataChanged();
}

IDFServiceInputData IDFStore::getInputData() const {
    return m_serviceInputData;
}

void IDFStore::setOutputData(const IDFServiceOutputData& outputData) {
    m_serviceOutputData = outputData;
    emit outputDataChanged();
}

IDFServiceOutputData IDFStore::getOutputData() const {
    return m_serviceOutputData;
}
