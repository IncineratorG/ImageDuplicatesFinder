#include "ResultViewTypesModel.h"
#include <QDebug>



ResultViewTypesModel::ResultViewTypesModel() {
    beginResetModel();
    m_modelData.clear();
    m_modelData.append("Все изображения");
    m_modelData.append("Папки");
    endResetModel();

    setCurrentIndex(0);
}

qint64 ResultViewTypesModel::getCurrentIndex() const {
    return m_currentIndex;
}

void ResultViewTypesModel::setCurrentIndex(qint64 value) {
    if (value < 0 || value >= m_modelData.size()) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_INDEX: " << value;
        return;
    }

    m_currentIndex = value;

    emit currentIndexChanged(getCurrentIndex());
}

// ============== Функции, наследуемые от QAbstractListModel ================
int ResultViewTypesModel::rowCount(const QModelIndex& parent) const {
    return m_modelData.size();
}

QVariant ResultViewTypesModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= m_modelData.size()) {
        return QVariant();
    }

    switch (role) {
        case IDRole: {
            return index.row();
        }

        case TypeNameRole: {
            return m_modelData.at(index.row());
        }
    }

    return QVariant();
}

QHash<int, QByteArray> ResultViewTypesModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IDRole] = "typeId";
    roles[TypeNameRole] = "modelData";

    return roles;
}
// ==========================================================================
