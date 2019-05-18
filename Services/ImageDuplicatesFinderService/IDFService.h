#ifndef IDFSERVICE_H
#define IDFSERVICE_H

#include <QObject>
#include <QThread>
#include "Data/IDFServiceInputData.h"
#include "Data/IDFServiceOutputData.h"
#include "Pipeline/IDFServiceProcessingPipeline.h"
#include <memory>



class IDFService : public QObject
{
    Q_OBJECT

public:
    IDFService();
    ~IDFService();

    void start(const IDFServiceInputData& input);
    void stop();

    IDFServiceOutputData getOutputData() const;

signals:
    void started();
    void interrupted();
    void finished();

    void startPipeline();
    void interruptPipeline();

private slots:
    void onPipelineStarted();
    void onPipelineInterrupted();
    void onPipelineFinished(IDFServiceOutputData outputData);

    void onStatusChanged(QString value);

private:
    QThread m_pipelineThread;

    IDFServiceProcessingPipeline m_pipeline;

    IDFServiceOutputData m_serviceOutputData;
};

#endif // IDFSERVICE_H
