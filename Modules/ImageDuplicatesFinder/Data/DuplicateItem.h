#ifndef DUPLICATEITEM_H
#define DUPLICATEITEM_H

#include <QString>



class DuplicateItem
{
public:
    DuplicateItem();
    DuplicateItem(const QString& imagePath);
    DuplicateItem(const DuplicateItem& other);

    QString getImagePath() const;

private:
    QString m_imagePath;
};

#endif // DUPLICATEITEM_H
