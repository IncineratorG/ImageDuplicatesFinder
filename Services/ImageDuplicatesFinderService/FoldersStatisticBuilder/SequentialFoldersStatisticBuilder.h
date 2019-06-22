#ifndef SEQUENTIALFOLDERSSTATISTICBUILDER_H
#define SEQUENTIALFOLDERSSTATISTICBUILDER_H

#include "AbstractFoldersStatisticBuilder.h"



class SequentialFoldersStatisticBuilder : public AbstractFoldersStatisticBuilder
{
public:
    SequentialFoldersStatisticBuilder();

    void setImagesDuplicatesGroups(std::shared_ptr<ImagesDuplicatesGroups> imagesDuplicatesGroups);
    std::shared_ptr<FoldersInfos> getFoldersInfos();

    void run();

private:
    std::shared_ptr<ImagesDuplicatesGroups> m_imagesDuplicatesGroups;
    std::shared_ptr<FoldersInfos> m_foldersInfos;

    const QString OPERATION_NAME;

    void doWork();
};

#endif // SEQUENTIALFOLDERSSTATISTICBUILDER_H
