#include "ImageHistogram.h"
#include <QDebug>
#include <cmath>



ImageHistogram::ImageHistogram() {

}

ImageHistogram::ImageHistogram(const QString& imagePath) {
    m_imagePath = imagePath;
    calculateHistogram();
}

ImageHistogram::ImageHistogram(const ImageHistogram& other) {
    copyFrom(other);
}

void ImageHistogram::setImage(const QString& imagePath) {
    m_imagePath = imagePath;
    calculateHistogram();
}

void ImageHistogram::clear() {
    for (int i = 0; i < CHANNELS; ++i) {
        for (int j = 0; j < CHANNEL_SIZE; ++j) {
            m_currentHistogramData[i][j] = 0;
        }
    }

    m_imagePath.clear();
    m_isEmpty = true;
}

bool ImageHistogram::isEmpty() const {
    return m_isEmpty;
}

QString ImageHistogram::getImagePath() const {
    return m_imagePath;
}

ImageHistogram& ImageHistogram::operator=(const ImageHistogram& other) {
    copyFrom(other);
    return *this;
}

float ImageHistogram::similarityScore(const ImageHistogram& histogram) const {
    QList<float> result;

    float redChannleNom = 0.0;
    float redChannelDenom = 0.0;
    float greenChannelNom = 0.0;
    float greenChannelDenom = 0.0;
    float blueChannelNom = 0.0;
    float blueChannelDenom = 0.0;

    for (int bin = 0; bin < CHANNEL_SIZE; ++bin) {
        if (m_currentHistogramData[RED_CHANNEL][bin] < histogram.m_currentHistogramData[RED_CHANNEL][bin]) {
            redChannleNom = m_currentHistogramData[RED_CHANNEL][bin];
            redChannelDenom = histogram.m_currentHistogramData[RED_CHANNEL][bin];
        } else {
            redChannleNom = histogram.m_currentHistogramData[RED_CHANNEL][bin];
            redChannelDenom = m_currentHistogramData[RED_CHANNEL][bin];
        }

        if (std::isnan(redChannleNom / redChannelDenom)) {
            result.append(0);
        } else {
            result.append(redChannleNom / redChannelDenom);
        }

        if (m_currentHistogramData[GREEN_CHANNEL][bin] < histogram.m_currentHistogramData[GREEN_CHANNEL][bin]) {
            greenChannelNom = m_currentHistogramData[GREEN_CHANNEL][bin];
            greenChannelDenom = histogram.m_currentHistogramData[GREEN_CHANNEL][bin];
        } else {
            greenChannelNom = histogram.m_currentHistogramData[GREEN_CHANNEL][bin];
            greenChannelDenom = m_currentHistogramData[GREEN_CHANNEL][bin];
        }

        if (std::isnan(greenChannelNom / greenChannelDenom)) {
            result.append(0);
        } else {
            result.append(greenChannelNom / greenChannelDenom);
        }

        if (m_currentHistogramData[BLUE_CHANNEL][bin] < histogram.m_currentHistogramData[BLUE_CHANNEL][bin]) {
            blueChannelNom = m_currentHistogramData[BLUE_CHANNEL][bin];
            blueChannelDenom = histogram.m_currentHistogramData[BLUE_CHANNEL][bin];
        } else {
            blueChannelNom = histogram.m_currentHistogramData[BLUE_CHANNEL][bin];
            blueChannelDenom = m_currentHistogramData[BLUE_CHANNEL][bin];
        }

        if (std::isnan(blueChannelNom / blueChannelDenom)) {
            result.append(0);
        } else {
            result.append(blueChannelNom / blueChannelDenom);
        }
    }

    float similarityScore = 0.0;
    for (int i = 0; i < result.size(); ++i) {
        similarityScore = similarityScore + result.at(i);
    }

    similarityScore = similarityScore / result.size();

    return similarityScore;
}

void ImageHistogram::copyFrom(const ImageHistogram& other) {
    m_imagePath = other.m_imagePath;
    m_isEmpty = other.m_isEmpty;

    std::copy(&other.m_currentHistogramData[0][0],
              &other.m_currentHistogramData[0][0] + CHANNELS * CHANNEL_SIZE,
              &m_currentHistogramData[0][0]);
}

void ImageHistogram::calculateHistogram() {
    for (int i = 0; i < CHANNELS; ++i) {
        for (int j = 0; j < CHANNEL_SIZE; ++j) {
            m_currentHistogramData[i][j] = 0;
        }
    }

    QImage currentImage(m_imagePath);
    if (currentImage.isNull()) {
        return;
    }

    for (int y = 0; y < currentImage.height(); ++y) {
        for (int x = 0; x < currentImage.width(); ++x) {
             QColor color(currentImage.pixel(x, y));

            m_currentHistogramData[RED_CHANNEL][color.red()] = m_currentHistogramData[RED_CHANNEL][color.red()] + 1;
            m_currentHistogramData[GREEN_CHANNEL][color.green()] = m_currentHistogramData[GREEN_CHANNEL][color.green()] + 1;
            m_currentHistogramData[BLUE_CHANNEL][color.blue()] = m_currentHistogramData[BLUE_CHANNEL][color.blue()] + 1;
        }
    }

    m_isEmpty = false;

    normalizeHistogram();
}

void ImageHistogram::normalizeHistogram() {
    float maximumChannelTotal = 0;

    for (int binIndex = 0; binIndex < CHANNEL_SIZE; ++binIndex) {
        float channelTotal = m_currentHistogramData[RED_CHANNEL][binIndex] +
                             m_currentHistogramData[GREEN_CHANNEL][binIndex] +
                             m_currentHistogramData[BLUE_CHANNEL][binIndex];

        if (channelTotal > maximumChannelTotal) {
            maximumChannelTotal = channelTotal;
        }
    }

    if (maximumChannelTotal <= 0) {
        return;
    }

    for (int bin = 0; bin < CHANNEL_SIZE; ++bin) {
        m_currentHistogramData[RED_CHANNEL][bin] /= maximumChannelTotal;
        m_currentHistogramData[GREEN_CHANNEL][bin] /= maximumChannelTotal;
        m_currentHistogramData[BLUE_CHANNEL][bin] /= maximumChannelTotal;
    }
}
