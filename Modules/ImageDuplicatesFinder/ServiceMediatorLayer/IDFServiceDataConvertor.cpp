#include "IDFServiceDataConvertor.h"
#include <QDebug>



IDFServiceDataConvertor::IDFServiceDataConvertor() {
    m_idGenerator = IdGenerator::getInstance();
}

void IDFServiceDataConvertor::convertAndSave(const IDFServiceOutputData& serviceOutputData,
                                             IDFServiceDataWarehouse* dataWarehouse) const
{
    if (dataWarehouse == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->DATA_WAREHOUSE_IS_NULL";
        return;
    }

    dataWarehouse->setModelDuplicatesGroups(getDuplicateItemsGroups(serviceOutputData));
}

DuplicateItemsGroups IDFServiceDataConvertor::getDuplicateItemsGroups(const IDFServiceOutputData& serviceOutputData) const {
    auto mutableServiceOutputData = serviceOutputData;
    auto serviceDuplicatesGroupList = mutableServiceOutputData.getDuplicatesGroups()->getGroupsList();

    QList<DuplicateItemsGroup> modelDuplicateItemsGroupsList;

    for (int i = 0; i < serviceDuplicatesGroupList.size(); ++i) {
        auto duplicatesGroup = serviceDuplicatesGroupList.at(i);
        auto duplicatesGroupImagesList = duplicatesGroup.getImagesList();

        DuplicateItemsGroup modelDuplicatesGroup;

        for (int j = 0; j < duplicatesGroupImagesList.size(); ++j) {
            modelDuplicatesGroup.appendDuplicate(DuplicateItem(duplicatesGroupImagesList.at(j)));
        }

        if (modelDuplicatesGroup.getGroupSize() > 0) {
            modelDuplicateItemsGroupsList.append(modelDuplicatesGroup);
        }
    }

    DuplicateItemsGroups modelDuplicatesGroups(modelDuplicateItemsGroupsList);

    return modelDuplicatesGroups;
}
