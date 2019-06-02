#include "DuplicateItemsGroupsModel.h"



DuplicateItemsGroupsModel::DuplicateItemsGroupsModel()
    : QML_FOLDER_PREFIX("file:///")
{
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
//    modelData.append(DuplicateItemsGroup());
}

//void DuplicateItemsGroupsModel::fillModel(const DuplicateItemsGroups& groups) {
//    beginResetModel();
//    for (int i = 0; i < 10000; ++i) {
//        DuplicateItemsGroup group;
//        group.appendDuplicate(DuplicateItem("C:/Users/Alexander/Downloads/TEST_IMAGES/Photos/DSC01935.JPG"));

//        modelData.append(group);
//    }
////    modelData = groups.getGroupsList();
////    modelData.append(groups.getGroupsList());
////    modelData.append(groups.getGroupsList());
////    modelData.append(groups.getGroupsList());
////    modelData.append(groups.getGroupsList());
////    modelData.append(groups.getGroupsList());
////    modelData.append(groups.getGroupsList());
//    endResetModel();

//    emit sizeChanged(getSize());
//}
void DuplicateItemsGroupsModel::fillModel(const DuplicateItemsGroups& groups) {
    beginResetModel();
    modelData = groups.getGroupsList();
    endResetModel();

    emit sizeChanged(getSize());
}

void DuplicateItemsGroupsModel::clear() {
    beginResetModel();
    modelData.clear();
    endResetModel();

    emit sizeChanged(getSize());
}

int DuplicateItemsGroupsModel::getSize() const {
    return rowCount();
}

void DuplicateItemsGroupsModel::updateGroup(const DuplicateItemsGroup& group) {
    for (int i = 0; i < modelData.size(); ++i) {
        if (modelData.at(i).getId() == group.getId()) {
            modelData.replace(i, group);

            emit dataChanged(createIndex(i, 0), createIndex(i, 0));

            break;
        }
    }
}

// ============== Функции, наследуемые от QAbstractListModel ================
int DuplicateItemsGroupsModel::rowCount(const QModelIndex& parent) const {
    return modelData.size();
}

QVariant DuplicateItemsGroupsModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= modelData.size()) {
        return QVariant();
    }

    auto duplicateGroup = modelData.at(index.row());

    switch (role) {
        case IDRole: {
            return duplicateGroup.getId();
        }

        case DuplicateImagePathRole: {
            auto duplicateGroupItemsList = duplicateGroup.getDuplicateItemsList();
            if (duplicateGroupItemsList.size() <= 0) {
                return "";
            }

            return QML_FOLDER_PREFIX + duplicateGroupItemsList.at(0).getImagePath();
        }

        case DuplicatesGroupSizeRole: {
            return duplicateGroup.getGroupSize();
        }
    }

    return QVariant();
}

QHash<int, QByteArray> DuplicateItemsGroupsModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "groupId";
    roles[DuplicateImagePathRole] = "imagePath";
    roles[DuplicatesGroupSizeRole] = "groupSize";

    return roles;
}
// ==========================================================================
