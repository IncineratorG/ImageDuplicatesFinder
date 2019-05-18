#ifndef IMAGEDUPLICATESGROUP_H
#define IMAGEDUPLICATESGROUP_H

#include <QMap>



class ImageDuplicatesGroup
{
public:
    ImageDuplicatesGroup();
    ImageDuplicatesGroup(const ImageDuplicatesGroup& other);

    bool isEmpty() const;

    void clear();

    void appendImage(const QString& imagePath, float similarityScore);
    bool removeImage(const QString& imagePath);

    float getSimilarityScore(const QString& imagePath) const;

    QList<QString> getImagesList() const;
    int getDuplicatesListSise() const;

    bool operator==(const ImageDuplicatesGroup& other) const;

private:
    QMap<QString, float> m_duplicates;
};

#endif // IMAGEDUPLICATESGROUP_H
