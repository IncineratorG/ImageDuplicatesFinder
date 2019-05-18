#include "ImagesHistograms.h"



ImagesHistograms::ImagesHistograms() {

}

ImagesHistograms::ImagesHistograms(const QList<ImageHistogram>& histograms)
    : m_histograms(histograms)
{

}

ImagesHistograms::ImagesHistograms(const ImagesHistograms& other)
    : m_histograms(other.m_histograms)
{

}

void ImagesHistograms::appendImageHistogram(const ImageHistogram& histogram) {
    m_histograms.append(histogram);
}

QList<ImageHistogram> ImagesHistograms::getHistograms() const {
    return m_histograms;
}

void ImagesHistograms::clear() {
    m_histograms.clear();
}
