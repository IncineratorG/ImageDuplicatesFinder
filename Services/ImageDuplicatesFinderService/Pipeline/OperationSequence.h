#ifndef OPERATIONSEQUENCE_H
#define OPERATIONSEQUENCE_H

#include <QPair>
#include "AbstractOperation.h"



class OperationSequence
{
public:
    OperationSequence();
    OperationSequence(AbstractOperation* op1, AbstractOperation* op2);
    OperationSequence(const OperationSequence& other);

    AbstractOperation* getFirstOperation() const;
    AbstractOperation* getSecondOperation() const;

    bool operator<(const OperationSequence& other) const {
        return this->m_sequence < other.m_sequence;
    }

private:
    QPair<AbstractOperation*, AbstractOperation*> m_sequence;
};

//uint qHash(const OperationSequence& seq) {
//    return qHash(qMakePair(seq.getFirstOperation(), seq.getSecondOperation()));
//}

#endif // OPERATIONSEQUENCE_H
