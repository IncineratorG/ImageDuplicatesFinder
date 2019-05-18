#ifndef SEQUENTIALHISTOGRAMSCOMPARATOR_H
#define SEQUENTIALHISTOGRAMSCOMPARATOR_H

#include "AbstractHistogramsComparator.h"



class SequentialHistogramsComparator : public AbstractHistogramsComparator
{
public:
    SequentialHistogramsComparator();

    void setImagesHistograms(std::shared_ptr<ImagesHistograms> histograms);
    std::shared_ptr<ImagesDuplicatesGroups> getImagesDuplicates();

    void run();

private:
    std::shared_ptr<ImagesHistograms> m_histograms;
    std::shared_ptr<ImagesDuplicatesGroups> m_duplicatesGroups;

    const float CRITICAL_SIMILARITY_SCORE;

    void doWork();
};

#endif // SEQUENTIALHISTOGRAMSCOMPARATOR_H
