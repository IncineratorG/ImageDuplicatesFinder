#ifndef DUPLICATEITEMSGROUPSMODEL_H
#define DUPLICATEITEMSGROUPSMODEL_H

#include <QAbstractListModel>
#include "../Data/DuplicateItemsGroups.h"



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

    void fillModel(const DuplicateItemsGroups& groups);

    void clear();

    int getSize() const;

    void updateGroup(const DuplicateItemsGroup& group);
    void removeGroup(const qint64 groupId);

    // ============== Функции, наследуемые от QAbstractListModel ================
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    // ==========================================================================

signals:
    void sizeChanged(int value);

private:
    QList<DuplicateItemsGroup> modelData;

    const QString QML_FOLDER_PREFIX;
};

#endif // DUPLICATEITEMSGROUPSMODEL_H
