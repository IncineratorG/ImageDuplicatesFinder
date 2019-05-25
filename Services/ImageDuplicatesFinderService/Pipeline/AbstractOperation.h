#ifndef ABSTRACTOPERATION_H
#define ABSTRACTOPERATION_H

#include <QThread>



class AbstractOperation : public QThread
{
    Q_OBJECT

public:
    AbstractOperation();
    virtual ~AbstractOperation() = 0;

    virtual void setNextOperation(AbstractOperation* op);
    virtual AbstractOperation* getNextOperation();

    virtual QString getOperationName();

private:
    AbstractOperation* m_nextOperation;
};

#endif // ABSTRACTOPERATION_H
