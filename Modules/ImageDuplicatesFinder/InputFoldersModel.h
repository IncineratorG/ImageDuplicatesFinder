#ifndef INPUTFOLDERSMODEL_H
#define INPUTFOLDERSMODEL_H

#include <QAbstractListModel>



class InputFoldersModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum InputFoldersModelRoles {
        IDRole = Qt::UserRole + 1,
        FolderPathRole
    };

    InputFoldersModel();

    void fillModel();

    void clear();

    // ============== Функции, наследуемые от QAbstractListModel ================
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    // ==========================================================================

private:
    QList<QString> modelData;
};

#endif // INPUTFOLDERSMODEL_H
