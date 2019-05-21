#ifndef INPUTFOLDERSMODEL_H
#define INPUTFOLDERSMODEL_H

#include <QAbstractListModel>
#include "InputFoldersModelItem.h"



class InputFoldersModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)

public:
    enum InputFoldersModelRoles {
        IDRole = Qt::UserRole + 1,
        FolderPathRole,
        ProcessSubpathsRole
    };

    InputFoldersModel();

    void fillModel();

    void clear();

    void addFolder(const InputFoldersModelItem& modelItem);
    void updateFolder(const int folderRow, const InputFoldersModelItem& modelItem);
    void removeFolder(const int folderRow);

    int getSize() const;

    // ============== Функции, наследуемые от QAbstractListModel ================
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    // ==========================================================================

signals:
    void sizeChanged(int value);

private:
    QList<InputFoldersModelItem> modelData;
};

#endif // INPUTFOLDERSMODEL_H
