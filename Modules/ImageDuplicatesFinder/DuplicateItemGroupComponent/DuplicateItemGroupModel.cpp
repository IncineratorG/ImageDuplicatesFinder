#include "DuplicateItemGroupModel.h"



DuplicateItemGroupModel::DuplicateItemGroupModel()
    : generalImagePath(""),
      QML_FOLDER_PREFIX("file:///")
{

}

void DuplicateItemGroupModel::fillModel(const DuplicateItemsGroup& group) {
    generalImagePath = "";

    beginResetModel();
    modelData = group.getDuplicateItemsList();
    endResetModel();

    emit sizeChanged(getSize());
    emit generalImageChanged(getGeneralImage());
    emit generalImagePathTextChanged(getGeneralImagePathText());
}

void DuplicateItemGroupModel::clear() {
    generalImagePath.clear();

    beginResetModel();
    modelData.clear();
    endResetModel();

    emit sizeChanged(getSize());
    emit generalImageChanged(getGeneralImage());
    emit generalImagePathTextChanged(getGeneralImagePathText());
}

int DuplicateItemGroupModel::getSize() const {
    return rowCount();
}

QString DuplicateItemGroupModel::getGeneralImage() const {
    if (!generalImagePath.isEmpty()) {
        return QML_FOLDER_PREFIX + generalImagePath;
    } else if (modelData.size() > 0) {
        return QML_FOLDER_PREFIX + modelData.at(0).getImagePath();
    } else {
        return "";
    }
}

QString DuplicateItemGroupModel::getGeneralImagePathText() const {
    if (!generalImagePath.isEmpty()) {
        return generalImagePath;
    } else if (modelData.size() > 0) {
        return modelData.at(0).getImagePath();
    } else {
        return "";
    }
}

void DuplicateItemGroupModel::setGeneralImagePath(const QString& imagePath) {
    generalImagePath = imagePath;

    emit generalImageChanged(getGeneralImage());
    emit generalImagePathTextChanged(getGeneralImagePathText());
}

qint64 DuplicateItemGroupModel::getItemIdByImagePath(const QString& imagePath) const {
    for (int i = 0; i < modelData.size(); ++i) {
        const QString& currentImagePath = modelData.at(i).getImagePath();
        if (currentImagePath == imagePath) {
            return modelData.at(i).getId();
        }
    }

    return -1;
}

bool DuplicateItemGroupModel::removeItem(const qint64 itemId) {
    for (int i = 0; i < modelData.size(); ++i) {
        if (modelData.at(i).getId() == itemId) {
            beginRemoveRows(QModelIndex(), i, i);
            modelData.removeAt(i);
            endRemoveRows();

            emit sizeChanged(getSize());
            emit generalImageChanged(getGeneralImage());
            emit generalImagePathTextChanged(getGeneralImagePathText());

            return true;
        }
    }

    return false;
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
