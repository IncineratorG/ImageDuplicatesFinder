#ifndef RESULTVIEWTYPESMODEL_H
#define RESULTVIEWTYPESMODEL_H

#include <QAbstractListModel>



class ResultViewTypesModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(qint64 currentIndex READ getCurrentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)

public:
    enum ResultViewTypesModelRoles {
        IDRole = Qt::UserRole + 1,
        TypeNameRole
    };

    ResultViewTypesModel();

    qint64 getCurrentIndex() const;

    void setCurrentIndex(qint64 value);

    // ============== Функции, наследуемые от QAbstractListModel ================
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    // ==========================================================================

signals:
    void currentIndexChanged(qint64 value);

private:
    QList<QString> m_modelData;

    qint64 m_currentIndex;
};

#endif // RESULTVIEWTYPESMODEL_H
