#include "OperationSequence.h"



OperationSequence::OperationSequence()
    : m_sequence(nullptr, nullptr)
{

}

OperationSequence::OperationSequence(AbstractOperation* op1, AbstractOperation* op2)
    : m_sequence(op1, op2)
{

}

OperationSequence::OperationSequence(const OperationSequence& other)
    : m_sequence(other.m_sequence)
{

}

AbstractOperation* OperationSequence::getFirstOperation() const {
    return m_sequence.first;
}

AbstractOperation* OperationSequence::getSecondOperation() const {
    return m_sequence.second;
}
