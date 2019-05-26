#ifndef OPERATIONPROGRESS_H
#define OPERATIONPROGRESS_H

#include <QString>



class OperationProgress
{
public:
    OperationProgress();
    OperationProgress(const QString& operationName);
    OperationProgress(const QString& operationName, const int progressLevel);
    OperationProgress(const OperationProgress& other);

    void clear();

    void setOperationName(const QString& operationName);
    void setProgressLevel(const int progressLevel);

    QString getOperationName() const;
    int getProgressLevel() const;

private:
    QString m_operationName;
    int m_progressLevel;
};

#endif // OPERATIONPROGRESS_H
