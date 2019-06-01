#include "IDFServiceDataConvertor.h"



IDFServiceDataConvertor::IDFServiceDataConvertor() {
    m_idGenerator = IdGenerator::getInstance();
}

DuplicateItemsGroups IDFServiceDataConvertor::toDuplicateItemsGroups(const IDFServiceOutputData& serviceOutput) const {
    auto mutableServiceOutputData = serviceOutput;
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
