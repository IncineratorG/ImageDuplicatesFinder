#ifndef DUPLICATEITEMGROUPMODEL_H
#define DUPLICATEITEMGROUPMODEL_H

#include <QAbstractListModel>
#include "../Data/DuplicateItemsGroup.h"



class DuplicateItemGroupModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int size                     READ getSize                 NOTIFY sizeChanged)
    Q_PROPERTY(QString generalImage         READ getGeneralImage         NOTIFY generalImageChanged)
    Q_PROPERTY(QString generalImagePathText READ getGeneralImagePathText NOTIFY generalImagePathTextChanged)

public:
    enum DuplicateItemGroupModelRoles {
        IDRole = Qt::UserRole + 1,
        DuplicateImagePathRole
    };

    DuplicateItemGroupModel();

    void fillModel(const DuplicateItemsGroup& group);

    void clear();

    int getSize() const;
    QString getGeneralImage() const;
    QString getGeneralImagePathText() const;

    void setGeneralImagePath(const QString& imagePath);

    qint64 getItemIdByImagePath(const QString& imagePath) const;
    QString getItemImagePath(const qint64 itemId) const;
    QString getItemImagePathText(const qint64 itemId) const;

    bool removeItem(const qint64 itemId);

    // ============== Функции, наследуемые от QAbstractListModel ================
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    // ==========================================================================

signals:
    void sizeChanged(int value);
    void generalImageChanged(QString value);
    void generalImagePathTextChanged(QString value);

private:
    QList<DuplicateItem> modelData;

    QString generalImagePath;

    const QString QML_FOLDER_PREFIX;
};

#endif // DUPLICATEITEMGROUPMODEL_H
