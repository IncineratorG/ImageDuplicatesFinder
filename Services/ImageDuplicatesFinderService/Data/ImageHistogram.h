#ifndef IMAGEHISTOGRAM_H
#define IMAGEHISTOGRAM_H

#include <QString>
#include <QImage>



class ImageHistogram
{
public:
    ImageHistogram();
    ImageHistogram(const QString& imagePath);
    ImageHistogram(const ImageHistogram& other);

    void setImage(const QString& imagePath);

    void clear();

    bool isEmpty() const;

    QString getImagePath() const;

    float similarityScore(const ImageHistogram& other) const;

    ImageHistogram& operator=(const ImageHistogram& other);

private:
    QString m_imagePath;

    bool m_isEmpty;

    const int RED_CHANNEL = 0;
    const int GREEN_CHANNEL = 1;
    const int BLUE_CHANNEL = 2;
    static const int CHANNELS = 3;
    static const int CHANNEL_SIZE = 256;

    float m_currentHistogramData[CHANNELS][CHANNEL_SIZE];


    void copyFrom(const ImageHistogram& other);

    void calculateHistogram();
    void normalizeHistogram();
};

//uint qHash(const ImageHistogram& histogram) {
//    return ::qHash(histogram.getImagePath());
//}

#endif // IMAGEHISTOGRAM_H
