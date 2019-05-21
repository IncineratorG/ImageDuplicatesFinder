#ifndef DUPLICATEITEMSLISTMODEL_H
#define DUPLICATEITEMSLISTMODEL_H

#include <QAbstractListModel>
#include "DuplicateItem.h"



class DuplicateItemsListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)

public:
    enum DuplicateItemsListModelRoles {
        IDRole = Qt::UserRole + 1,
        ImagePathRole
    };

    DuplicateItemsListModel();

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
    QList<DuplicateItem> modelData;
};

#endif // DUPLICATEITEMSLISTMODEL_H
