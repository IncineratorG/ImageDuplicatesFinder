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

    const DuplicateItemsGroups& duplicateItemsGroups = getDuplicateItemsGroups(serviceOutputData);
    const FolderInfoItemsList& folderInfoItemsList = getFolderInfoItemsList(duplicateItemsGroups);

    dataWarehouse->setModelDuplicatesGroups(duplicateItemsGroups);
    dataWarehouse->setModelFolderInfoItemsList(folderInfoItemsList);
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

FolderInfoItemsList IDFServiceDataConvertor::getFolderInfoItemsList(const DuplicateItemsGroups& duplicateItemsGroups) const {
    FolderInfoItemsList folderInfoItemsList;

    const QList<DuplicateItemsGroup>& groupsList = duplicateItemsGroups.getGroupsList();
    for (int i = 0; i < groupsList.size(); ++i) {
        const DuplicateItemsGroup& group = groupsList.at(i);

        const QList<DuplicateItem>& groupDuplicatesList = group.getDuplicateItemsList();
        for (int j = 0; j < groupDuplicatesList.size(); ++j) {
            const DuplicateItem& duplicateItem = groupDuplicatesList.at(j);

            folderInfoItemsList.appendDuplicateItem(duplicateItem);
        }
    }

//    // =====
//    qDebug() << __PRETTY_FUNCTION__;
//    const QList<FolderInfoItem>& folderInfoItemsList = folderInfoItems.getFoldersInfosList();
//    for (int i = 0; i < folderInfoItemsList.size(); ++i) {
//        const FolderInfoItem& folderInfo = folderInfoItemsList.at(i);

//        qDebug() << __PRETTY_FUNCTION__ << folderInfo.getFolderPath();
//        qDebug() << "TOTAL_FILES: " << folderInfo.getTotalFilesCount();
//        qDebug() << "TOTAL_IMAGES: " << folderInfo.getTotalImagesCount();
//        qDebug() << "DUPLICATE_IMAGES: " << folderInfo.getDuplicateImagesCount();
//        qDebug() << "SUBFOLDERS: " << folderInfo.getSubfoldersCount();
//        qDebug() << "";
//    }
//    // =====

    return folderInfoItemsList;
}
