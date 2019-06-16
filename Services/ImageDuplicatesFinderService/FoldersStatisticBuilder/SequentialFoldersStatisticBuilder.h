#ifndef SEQUENTIALFOLDERSSTATISTICBUILDER_H
#define SEQUENTIALFOLDERSSTATISTICBUILDER_H

#include "AbstractFoldersStatisticBuilder.h"



class SequentialFoldersStatisticBuilder : public AbstractFoldersStatisticBuilder
{
public:
    SequentialFoldersStatisticBuilder();

    void setImagesDuplicatesGroups(std::shared_ptr<ImagesDuplicatesGroups> imagesDuplicatesGroups);

    void run();

private:
    std::shared_ptr<ImagesDuplicatesGroups> m_imagesDuplicatesGroups;

    const QString OPERATION_NAME;

    void doWork();
};

#endif // SEQUENTIALFOLDERSSTATISTICBUILDER_H
