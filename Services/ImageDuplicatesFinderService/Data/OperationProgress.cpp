#include "OperationProgress.h"



OperationProgress::OperationProgress()
    : m_operationName(""),
      m_progressLevel(0)
{

}

OperationProgress::OperationProgress(const QString& operationName)
    : m_operationName(operationName),
      m_progressLevel(0)
{

}

OperationProgress::OperationProgress(const QString& operationName, const int progressLevel)
    : m_operationName(operationName),
      m_progressLevel(progressLevel)
{

}

OperationProgress::OperationProgress(const OperationProgress& other)
    : m_operationName(other.m_operationName),
      m_progressLevel(other.m_progressLevel)
{

}

void OperationProgress::clear() {
    m_operationName.clear();
    m_progressLevel = 0;
}

void OperationProgress::setOperationName(const QString& operationName) {
    m_operationName = operationName;
}

void OperationProgress::setProgressLevel(const int progressLevel) {
    m_progressLevel = progressLevel;
}

QString OperationProgress::getOperationName() const {
    return m_operationName;
}

int OperationProgress::getProgressLevel() const {
    return m_progressLevel;
}
