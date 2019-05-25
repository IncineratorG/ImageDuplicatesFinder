#include "IDFService.h"
#include <QDebug>



IDFService::IDFService() {
    m_pipeline.moveToThread(&m_pipelineThread);

    connect(this, SIGNAL(startPipeline()), &m_pipeline, SLOT(startPipeline()));
    connect(this, SIGNAL(interruptPipeline()), &m_pipeline, SLOT(interruptPipeline()), Qt::DirectConnection);
    connect(&m_pipeline, SIGNAL(pipelineStarted()), this, SLOT(onPipelineStarted()));
    connect(&m_pipeline, SIGNAL(pipelineInterrupted()), this, SLOT(onPipelineInterrupted()));
    connect(&m_pipeline, SIGNAL(pipelineFinished(IDFServiceOutputData)), this, SLOT(onPipelineFinished(IDFServiceOutputData)));
    connect(&m_pipeline, SIGNAL(statusChanged(QString)), this, SIGNAL(statusChanged(QString)));
    connect(&m_pipeline, SIGNAL(currentOperationNameChanged(QString)), this, SIGNAL(currentOperationNameChanged(QString)));

    m_pipelineThread.start();
}

IDFService::~IDFService() {
    m_pipeline.interruptPipeline();

    m_pipelineThread.quit();
    m_pipelineThread.wait();
}

void IDFService::start(const IDFServiceInputData& input) {
    qDebug() << __PRETTY_FUNCTION__;

    if (m_pipeline.getStatusEnum() == IDFServiceProcessingPipeline::PROCESSING) {
        qDebug() << __PRETTY_FUNCTION__ << "->PIPELINE_IS_BUSY";
        return;
    }

    m_pipeline.setInputData(input);

    emit startPipeline();
}

void IDFService::stop() {
    qDebug() << __PRETTY_FUNCTION__;

    if (m_pipeline.getStatusEnum() == IDFServiceProcessingPipeline::IDLE) {
        return;
    }

    emit interruptPipeline();
}

QString IDFService::getStatus() const {
    return m_pipeline.getStatus();
}

QString IDFService::getCurrentOperationName() const {
    return m_pipeline.getCurrentOperationName();
}

IDFServiceOutputData IDFService::getOutputData() const {
    return  m_serviceOutputData;
}

void IDFService::onPipelineStarted() {
    qDebug() << __PRETTY_FUNCTION__;

    emit started();
}

void IDFService::onPipelineInterrupted() {
    qDebug() << __PRETTY_FUNCTION__;

    emit interrupted();
}

void IDFService::onPipelineFinished(IDFServiceOutputData outputData) {
    qDebug() << __PRETTY_FUNCTION__;

    m_serviceOutputData = outputData;

    emit finished();
}

//void IDFService::onStatusChanged(QString value) {
//    qDebug() << __PRETTY_FUNCTION__ << value;
//}
