#include "InputFoldersModel.h"
#include <QDebug>



InputFoldersModel::InputFoldersModel() {
    modelData.append("C:/Users/Alexander/Videos");
    modelData.append("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug");
    modelData.append("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug");
    modelData.append("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug");
    modelData.append("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug");
    modelData.append("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug");
    modelData.append("C:/Users/Alexander/Documents/QtProjects/build-ImageDuplicatesFinder-Desktop_Qt_5_12_1_MinGW_64_bit-Debug");
}

void InputFoldersModel::fillModel() {

}

void InputFoldersModel::clear() {
    modelData.clear();
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
        case IDRole:
            return index.row();

        case FolderPathRole:
            return modelData.at(index.row());
    }

    return QVariant();
}

QHash<int, QByteArray> InputFoldersModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "folderId";
    roles[FolderPathRole] = "folderPath";

    return roles;
}
// ==========================================================================
