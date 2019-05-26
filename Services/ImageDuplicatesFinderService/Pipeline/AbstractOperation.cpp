#include "AbstractOperation.h"



AbstractOperation::AbstractOperation() {
    m_nextOperation = nullptr;
}

AbstractOperation::~AbstractOperation() {

}

void AbstractOperation::setNextOperation(AbstractOperation* op) {
    m_nextOperation = op;
}

AbstractOperation* AbstractOperation::getNextOperation() {
    return m_nextOperation;
}
