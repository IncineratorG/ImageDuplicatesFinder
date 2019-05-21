#include "DuplicateItemsListModel.h"



DuplicateItemsListModel::DuplicateItemsListModel() {

}

void DuplicateItemsListModel::fillModel() {
    emit sizeChanged(getSize());
}

void DuplicateItemsListModel::clear() {
    modelData.clear();

    emit sizeChanged(getSize());
}

int DuplicateItemsListModel::getSize() const {
    return rowCount();
}

// ============== Функции, наследуемые от QAbstractListModel ================
int DuplicateItemsListModel::rowCount(const QModelIndex& parent) const {
    return modelData.size();
}

QVariant DuplicateItemsListModel::data(const QModelIndex& index, int role) const {
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

QHash<int, QByteArray> DuplicateItemsListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "folderId";
    roles[ImagePathRole] = "imagePath";

    return roles;
}
// ==========================================================================
