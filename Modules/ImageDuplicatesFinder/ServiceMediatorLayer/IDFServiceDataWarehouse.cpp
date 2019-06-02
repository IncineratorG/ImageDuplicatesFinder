#include "IDFServiceDataWarehouse.h"
#include <QDebug>



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

DuplicateItemsGroup IDFServiceDataWarehouse::getModelDuplicateItemGroup(const qint64 groupId) const {
    const QList<DuplicateItemsGroup>& groupsList = m_modelDuplicatesGroups.getGroupsList();
    for (int i = 0; i < groupsList.size(); ++i) {
        const DuplicateItemsGroup group = groupsList.at(i);

        if (group.getId() == groupId) {
            return group;
        }
    }

    return DuplicateItemsGroup();
}
