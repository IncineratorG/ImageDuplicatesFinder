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

void DuplicateItemsGroupsModel::fillModel(const DuplicateItemsGroups& groups) {
    beginResetModel();
    modelData = groups.getGroupsList();
    endResetModel();

    emit sizeChanged(getSize());
}

void DuplicateItemsGroupsModel::clear() {
    modelData.clear();

    emit sizeChanged(getSize());
}

int DuplicateItemsGroupsModel::getSize() const {
    return rowCount();
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
            return index.row();
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
