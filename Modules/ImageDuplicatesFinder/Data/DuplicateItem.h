#ifndef DUPLICATEITEM_H
#define DUPLICATEITEM_H

#include <QString>



class DuplicateItem
{
public:
    DuplicateItem();
    DuplicateItem(const QString& imagePath);
    DuplicateItem(const DuplicateItem& other);

    qint64 getId() const;
    QString getImagePath() const;

    bool operator==(const DuplicateItem& other) {
        return this->m_imagePath == other.m_imagePath;
    }

private:
    QString m_imagePath;

    qint64 m_id;
};

#endif // DUPLICATEITEM_H
