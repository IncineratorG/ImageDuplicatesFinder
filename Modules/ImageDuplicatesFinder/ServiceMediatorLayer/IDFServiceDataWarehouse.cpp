#include "IDFServiceDataWarehouse.h"



IDFServiceDataWarehouse::IDFServiceDataWarehouse() {

}

void IDFServiceDataWarehouse::setInputData(const IDFServiceInputData& inputData) {
    m_serviceInputData = inputData;
}

IDFServiceInputData IDFServiceDataWarehouse::getInputData() const {
    return m_serviceInputData;
}
