#include "DuplicateItemsGroupsModel.h"



DuplicateItemsGroupsModel::DuplicateItemsGroupsModel() {

}

void DuplicateItemsGroupsModel::fillModel() {
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

//    switch (role) {
//        case IDRole: {
//            return index.row();
//        }

//        case FolderPathRole: {
//            return modelData.at(index.row()).getPath();
//        }

//        case ProcessSubpathsRole: {
//            return modelData.at(index.row()).getProcessSubpath();
//        }
//    }

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
