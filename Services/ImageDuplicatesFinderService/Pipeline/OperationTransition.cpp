#include "OperationTransition.h"



OperationTransition::OperationTransition()
    : m_action({})
{

}

OperationTransition::OperationTransition(std::function<void(void)> action)
     : m_action(action)
{

}

OperationTransition::OperationTransition(const OperationTransition& other)
    :  m_action(other.m_action)
{

}

void OperationTransition::setTransition(std::function<void ()> action) {
    m_action = action;
}

void OperationTransition::run() const {
    try {
        m_action();
    } catch (std::exception e) {

    }
}
