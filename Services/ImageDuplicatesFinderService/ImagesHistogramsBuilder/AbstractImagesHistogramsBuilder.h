#ifndef ABSTRACTIMAGESHISTOGRAMSBUILDER_H
#define ABSTRACTIMAGESHISTOGRAMSBUILDER_H

#include "../Data/ImagesPaths.h"
#include "../Data/ImagesHistograms.h"
#include "../Pipeline/AbstractOperation.h"



class AbstractImagesHistogramsBuilder : public AbstractOperation
{
public:
    virtual ~AbstractImagesHistogramsBuilder() = 0;

    virtual void setImagesPaths(std::shared_ptr<ImagesPaths> imagesPaths) = 0;
    virtual std::shared_ptr<ImagesHistograms> getImagesHistograms() = 0;
};

#endif // ABSTRACTIMAGESHISTOGRAMSBUILDER_H
