#include "PipelineOperationsTransitions.h"



PipelineOperationsTransitions::PipelineOperationsTransitions() {

}

PipelineOperationsTransitions::PipelineOperationsTransitions(const PipelineOperationsTransitions& other)
    : m_transitions(other.m_transitions)
{

}

void PipelineOperationsTransitions::clear() {
    m_transitions.clear();
}

void PipelineOperationsTransitions::setTransition(const OperationSequence& sequence, const OperationTransition& transition) {
    m_transitions.insert(sequence, transition);
}

bool PipelineOperationsTransitions::containSequence(const OperationSequence& sequence) const {
    return m_transitions.contains(sequence);
}

void PipelineOperationsTransitions::runTransition(const OperationSequence& sequence) const {
    if (!m_transitions.contains(sequence))
        return;

    m_transitions.value(sequence).run();
}
