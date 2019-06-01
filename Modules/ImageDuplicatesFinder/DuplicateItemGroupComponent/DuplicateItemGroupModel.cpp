#include "DuplicateItemGroupModel.h"



DuplicateItemGroupModel::DuplicateItemGroupModel()
    : QML_FOLDER_PREFIX("file:///")
{

}

void DuplicateItemGroupModel::fillModel(const DuplicateItemsGroup& group) {
    beginResetModel();
    modelData = group.getDuplicateItemsList();
    endResetModel();

    emit sizeChanged(getSize());
    emit generalImageChanged(getGeneralImage());
}

void DuplicateItemGroupModel::clear() {
    beginResetModel();
    modelData.clear();
    endResetModel();

    emit sizeChanged(getSize());
    emit generalImageChanged(getGeneralImage());
}

int DuplicateItemGroupModel::getSize() const {
    return rowCount();
}

QString DuplicateItemGroupModel::getGeneralImage() const {
    if (modelData.size() > 0) {
        return QML_FOLDER_PREFIX + modelData.at(0).getImagePath();
    }

    return "";
}

// ============== Функции, наследуемые от QAbstractListModel ================
int DuplicateItemGroupModel::rowCount(const QModelIndex& parent) const {
    return modelData.size();
}

QVariant DuplicateItemGroupModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= modelData.size()) {
        return QVariant();
    }

    auto duplicateItem = modelData.at(index.row());

    switch (role) {
        case IDRole: {
            return duplicateItem.getId();
        }

        case DuplicateImagePathRole: {
            return duplicateItem.getImagePath();
        }
    }

    return QVariant();
}

QHash<int, QByteArray> DuplicateItemGroupModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "itemId";
    roles[DuplicateImagePathRole] = "imagePath";

    return roles;
}
// ==========================================================================
