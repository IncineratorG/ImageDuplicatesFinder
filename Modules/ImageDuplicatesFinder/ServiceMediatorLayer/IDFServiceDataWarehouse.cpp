#include "IDFServiceDataWarehouse.h"



IDFServiceDataWarehouse::IDFServiceDataWarehouse() {

}

void IDFServiceDataWarehouse::setInputData(const IDFServiceInputData& inputData) {
    m_serviceInputData = inputData;
}

IDFServiceInputData IDFServiceDataWarehouse::getInputData() const {
    return m_serviceInputData;
}

void IDFServiceDataWarehouse::setModelDuplicatesGroups(const DuplicateItemsGroups& modelDuplicatesGroups) {
    m_modelDuplicatesGroups = modelDuplicatesGroups;
}

DuplicateItemsGroups IDFServiceDataWarehouse::getModelDuplicatesGroups() const {
    return m_modelDuplicatesGroups;
}
