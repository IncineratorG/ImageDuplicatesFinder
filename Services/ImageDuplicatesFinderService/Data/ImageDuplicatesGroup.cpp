#include "ImageDuplicatesGroup.h"



ImageDuplicatesGroup::ImageDuplicatesGroup() {

}

ImageDuplicatesGroup::ImageDuplicatesGroup(const ImageDuplicatesGroup& other)
    : m_duplicates(other.m_duplicates)
{

}

bool ImageDuplicatesGroup::isEmpty() const {
    return m_duplicates.isEmpty();
}

void ImageDuplicatesGroup::clear() {
    m_duplicates.clear();
}

void ImageDuplicatesGroup::appendImage(const QString& imagePath, float similarityScore) {
    m_duplicates.insert(imagePath, similarityScore);
}

bool ImageDuplicatesGroup::removeImage(const QString& imagePath) {
    if (!m_duplicates.contains(imagePath)) {
        return false;
    }

    m_duplicates.remove(imagePath);

    return true;
}

float ImageDuplicatesGroup::getSimilarityScore(const QString& imagePath) const {
    if (!m_duplicates.contains(imagePath)) {
        return -1.0f;
    }

    return m_duplicates.value(imagePath);
}

QList<QString> ImageDuplicatesGroup::getImagesList() const {
    return m_duplicates.keys();
}

int ImageDuplicatesGroup::getDuplicatesListSise() const {
    return m_duplicates.size();
}

bool ImageDuplicatesGroup::operator==(const ImageDuplicatesGroup& other) const {
    return m_duplicates == other.m_duplicates;
}
