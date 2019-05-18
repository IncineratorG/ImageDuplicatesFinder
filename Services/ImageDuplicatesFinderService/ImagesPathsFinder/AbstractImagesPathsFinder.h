#ifndef ABSTRACTIMAGESPATHSFINDER_H
#define ABSTRACTIMAGESPATHSFINDER_H

#include "../Data/Paths.h"
#include "../Data/ImagesPaths.h"
#include "../Pipeline/AbstractOperation.h"



class AbstractImagesPathsFinder : public AbstractOperation
{
public:
    virtual ~AbstractImagesPathsFinder() = 0;

    virtual void setPaths(std::shared_ptr<Paths> paths) = 0;
    virtual std::shared_ptr<ImagesPaths> getImagesPaths() = 0;
};

#endif // ABSTRACTIMAGESPATHSFINDER_H
