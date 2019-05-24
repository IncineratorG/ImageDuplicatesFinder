#include "InputFoldersModel.h"
#include <QDebug>



InputFoldersModel::InputFoldersModel() {
//    InputFoldersModelItem item_1("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug", true);
//    InputFoldersModelItem item_2("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug", false);

//    modelData.append(item_1);
//    modelData.append(item_2);

//    emit sizeChanged(getSize());
}

void InputFoldersModel::fillModel() {
    emit sizeChanged(getSize());
}

void InputFoldersModel::clear() {
    modelData.clear();

    emit sizeChanged(getSize());
}

void InputFoldersModel::addFolder(const InputFolderItem& modelItem) {
    beginInsertRows(QModelIndex(), modelData.size(), modelData.size());
    modelData.append(modelItem);
    endInsertRows();

    emit sizeChanged(getSize());
}

void InputFoldersModel::updateFolder(const int folderRow, const InputFolderItem& modelItem) {
    if (folderRow < 0 || folderRow >= modelData.size()) {
        return;
    }

    modelData.replace(folderRow, modelItem);

    emit dataChanged(createIndex(folderRow, 0), createIndex(folderRow, 0));
}

void InputFoldersModel::removeFolder(const int folderRow) {
    if (folderRow < 0 || folderRow >= modelData.size()) {
        return;
    }

    beginRemoveRows(QModelIndex(), folderRow, folderRow);
    modelData.removeAt(folderRow);
    endRemoveRows();

    emit sizeChanged(getSize());
}

int InputFoldersModel::getSize() const {
    return rowCount();
}

// ============== Функции, наследуемые от QAbstractListModel ================
int InputFoldersModel::rowCount(const QModelIndex& parent) const {
    return modelData.size();
}

QVariant InputFoldersModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= modelData.size()) {
        return QVariant();
    }

    switch (role) {
        case IDRole: {
            return index.row();
        }

        case FolderPathRole: {
            return modelData.at(index.row()).getPath();
        }

        case ProcessSubpathsRole: {
            return modelData.at(index.row()).getProcessSubpath();
        }
    }

    return QVariant();
}

QHash<int, QByteArray> InputFoldersModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "folderId";
    roles[FolderPathRole] = "folderPath";
    roles[ProcessSubpathsRole] = "processSubpaths";

    return roles;
}
// ==========================================================================
