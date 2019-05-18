#ifndef PIPELINEOPERATIONSTRANSITIONS_H
#define PIPELINEOPERATIONSTRANSITIONS_H

#include <QMap>
#include "OperationSequence.h"
#include "OperationTransition.h"



class PipelineOperationsTransitions
{
public:
    PipelineOperationsTransitions();
    PipelineOperationsTransitions(const PipelineOperationsTransitions& other);

    void clear();

    void setTransition(const OperationSequence& sequence, const OperationTransition& transition);

    bool containSequence(const OperationSequence& sequence) const;

    void runTransition(const OperationSequence& sequence) const;

private:
    QMap<OperationSequence, OperationTransition> m_transitions;
};

#endif // PIPELINEOPERATIONSTRANSITIONS_H
