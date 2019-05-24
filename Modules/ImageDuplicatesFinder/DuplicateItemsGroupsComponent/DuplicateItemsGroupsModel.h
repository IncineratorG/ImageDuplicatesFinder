#ifndef DUPLICATEITEMSGROUPSMODEL_H
#define DUPLICATEITEMSGROUPSMODEL_H

#include <QAbstractListModel>
#include "../Data/DuplicateItemsGroup.h"



class DuplicateItemsGroupsModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)

public:
    enum DuplicateItemsGroupsModelRoles {
        IDRole = Qt::UserRole + 1,
        DuplicateImagePathRole,
        DuplicatesGroupSizeRole
    };

    DuplicateItemsGroupsModel();

    void fillModel();

    void clear();

    int getSize() const;

    // ============== Функции, наследуемые от QAbstractListModel ================
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    // ==========================================================================

signals:
    void sizeChanged(int value);

private:
    QList<DuplicateItemsGroup> modelData;
};

#endif // DUPLICATEITEMSGROUPSMODEL_H
