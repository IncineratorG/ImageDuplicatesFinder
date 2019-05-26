#ifndef SEQUETIALINPUTPATHSPREPARATOR_H
#define SEQUETIALINPUTPATHSPREPARATOR_H

#include "AbstractInputPathsPreparator.h"



class SequetialInputPathsPreparator : public AbstractInputPathsPreparator
{
public:
    SequetialInputPathsPreparator();

    void setInputData(IDFServiceInputData inputData);
    Paths getPaths();

    void run();

private:
    IDFServiceInputData m_serviceInputData;
    Paths m_inputPaths;

    const QString OPERATION_NAME;

    void doWork();

    void toPaths_r(const QDir& directory, Paths& paths);
};

#endif // SEQUETIALINPUTPATHSPREPARATOR_H
