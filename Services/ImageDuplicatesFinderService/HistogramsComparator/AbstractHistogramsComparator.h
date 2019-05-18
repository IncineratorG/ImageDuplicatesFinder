#ifndef ABSTRACTHISTOGRAMSCOMPARATOR_H
#define ABSTRACTHISTOGRAMSCOMPARATOR_H

#include "../Data/ImagesHistograms.h"
#include "../Data/ImagesDuplicatesGroups.h"
#include "../Pipeline/AbstractOperation.h"



class AbstractHistogramsComparator : public AbstractOperation
{
public:
    virtual ~AbstractHistogramsComparator() = 0;

    virtual void setImagesHistograms(std::shared_ptr<ImagesHistograms> histograms) = 0;
    virtual std::shared_ptr<ImagesDuplicatesGroups> getImagesDuplicates() = 0;
};

#endif // ABSTRACTHISTOGRAMSCOMPARATOR_H
