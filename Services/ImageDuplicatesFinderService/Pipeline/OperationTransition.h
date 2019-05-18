#ifndef OPERATIONTRANSITION_H
#define OPERATIONTRANSITION_H

#include <functional>
#include "OperationSequence.h"



class OperationTransition
{
public:
    OperationTransition();
    OperationTransition(std::function<void(void)> action);
    OperationTransition(const OperationTransition& other);

    void setTransition(std::function<void(void)> action);

    void run() const;

private:
    std::function<void(void)> m_action;
};

#endif // OPERATIONTRANSITION_H
