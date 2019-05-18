#ifndef IMAGESHISTOGRAMS_H
#define IMAGESHISTOGRAMS_H

#include <QList>
#include "ImageHistogram.h"



class ImagesHistograms
{
public:
    ImagesHistograms();
    ImagesHistograms(const QList<ImageHistogram>& histograms);
    ImagesHistograms(const ImagesHistograms& other);

    void appendImageHistogram(const ImageHistogram& histogram);
    QList<ImageHistogram> getHistograms() const;

    void clear();

private:
    QList<ImageHistogram> m_histograms;
};

#endif // IMAGESHISTOGRAMS_H
