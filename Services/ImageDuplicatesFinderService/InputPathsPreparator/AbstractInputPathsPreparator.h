#ifndef ABSTRACTINPUTPATHSPREPARATOR_H
#define ABSTRACTINPUTPATHSPREPARATOR_H

#include "../Data/Paths.h"
#include "../Data/IDFServiceInputData.h"
#include "../Pipeline/AbstractOperation.h"



class AbstractInputPathsPreparator : public AbstractOperation
{
public:
    virtual ~AbstractInputPathsPreparator() = 0;

    virtual void setInputData(IDFServiceInputData inputData) = 0;
    virtual Paths getPaths() = 0;
};

#endif // ABSTRACTINPUTPATHSPREPARATOR_H
