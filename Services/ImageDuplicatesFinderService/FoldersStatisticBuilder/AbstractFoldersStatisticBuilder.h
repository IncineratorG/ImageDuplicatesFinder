#ifndef ABSTRACTFOLDERSSTATISTICBUILDER_H
#define ABSTRACTFOLDERSSTATISTICBUILDER_H

#include "../Data/ImagesDuplicatesGroups.h"
#include "../Data/FoldersInfos.h"
#include "../Pipeline/AbstractOperation.h"



class AbstractFoldersStatisticBuilder : public AbstractOperation
{
public:
    virtual ~AbstractFoldersStatisticBuilder() = 0;

    virtual void setImagesDuplicatesGroups(std::shared_ptr<ImagesDuplicatesGroups> imagesDuplicatesGroups) = 0;
    virtual std::shared_ptr<FoldersInfos> getFoldersInfos() = 0;
};

#endif // ABSTRACTFOLDERSSTATISTICBUILDER_H
