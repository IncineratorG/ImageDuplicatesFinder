#ifndef SEQUENTIALIMAGESHISTOGRAMSBUILDER_H
#define SEQUENTIALIMAGESHISTOGRAMSBUILDER_H

#include "AbstractImagesHistogramsBuilder.h"



class SequentialImagesHistogramsBuilder : public AbstractImagesHistogramsBuilder
{
public:
    SequentialImagesHistogramsBuilder();

    void setImagesPaths(std::shared_ptr<ImagesPaths> imagesPaths);
    std::shared_ptr<ImagesHistograms> getImagesHistograms();

    void run();

private:
    std::shared_ptr<ImagesPaths> m_imagesPaths;
    std::shared_ptr<ImagesHistograms> m_histograms;

    void doWork();
};

#endif // SEQUENTIALIMAGESHISTOGRAMSBUILDER_H
