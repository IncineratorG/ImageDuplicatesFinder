#ifndef SEQUETIALINPUTPATHSPREPARATOR_H
#define SEQUETIALINPUTPATHSPREPARATOR_H

#include "AbstractInputPathsPreparator.h"



class SequetialInputPathsPreparator : public AbstractInputPathsPreparator
{
public:
    SequetialInputPathsPreparator();

    void setInputData(IDFServiceInputData inputData);
    Paths getPaths();

    QString getOperationName();

    void run();

private:
    IDFServiceInputData m_serviceInputData;
    Paths m_inputPaths;

    const QString OPERATION_NAME;

    void doWork();
};

#endif // SEQUETIALINPUTPATHSPREPARATOR_H
