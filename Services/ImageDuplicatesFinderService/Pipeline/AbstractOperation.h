#ifndef ABSTRACTOPERATION_H
#define ABSTRACTOPERATION_H

#include <QThread>
#include "Services/ImageDuplicatesFinderService/Data/OperationProgress.h"



class AbstractOperation : public QThread
{
    Q_OBJECT

public:
    AbstractOperation();
    virtual ~AbstractOperation() = 0;

    virtual void setNextOperation(AbstractOperation* op);
    virtual AbstractOperation* getNextOperation();

signals:
    void publishProgress(OperationProgress value);

private:
    AbstractOperation* m_nextOperation;
};

#endif // ABSTRACTOPERATION_H
