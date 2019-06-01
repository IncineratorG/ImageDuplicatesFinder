#include "IDFServiceController.h"
#include <QDebug>



IDFServiceController* IDFServiceController::m_instance = nullptr;

IDFServiceController* IDFServiceController::getInstance() {
    if (!m_instance) {
        m_instance = new IDFServiceController();
    }

    return m_instance;
}

IDFServiceController::IDFServiceController() {
    connect(&m_idfService, SIGNAL(started()), this, SLOT(onServiceStarted()));
    connect(&m_idfService, SIGNAL(interrupted()), this, SLOT(onServiceInterrupted()));
    connect(&m_idfService, SIGNAL(finished()), this, SLOT(onServiceFinished()));
    connect(&m_idfService, SIGNAL(statusChanged(QString)), this, SIGNAL(serviceStatusChanged(QString)));
    connect(&m_idfService, SIGNAL(publishProgress(OperationProgress)), this, SLOT(onPublishProgress(OperationProgress)));
}

void IDFServiceController::startService() {
    m_idfService.start(m_dataWarehouse.getInputData());
}

void IDFServiceController::stopService() {
    m_idfService.stop();
}

QString IDFServiceController::getServiceStatus() const {
    return m_idfService.getStatus();
}

QString IDFServiceController::getCurrentServiceOperationName() const {
    return m_currentOperationProgress.getOperationName();
}

QString IDFServiceController::getCurrentServiceOperationProgress() const {
    return QString::number(m_currentOperationProgress.getProgressLevel()) + " %";
}

IDFServiceInputData IDFServiceController::getInputData() const {
    return m_dataWarehouse.getInputData();
}

void IDFServiceController::addInputFolder(const QString& folderPath, const bool processSubpath) {
    IDFServiceInputData currentInputData = m_dataWarehouse.getInputData();

    currentInputData.appendInputDataItem(IDFServiceInputDataItem(folderPath, processSubpath));

    m_dataWarehouse.setInputData(currentInputData);
}

bool IDFServiceController::updateInputFolder(const int folderRow, const QString& folderPath, const bool processSubpath) {
    IDFServiceInputData currentInputData = m_dataWarehouse.getInputData();

    QList<IDFServiceInputDataItem> inputDataItemsList = currentInputData.getInputDataList();
    if (folderRow < 0 || folderRow >= inputDataItemsList.size()) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_UPDATE_SERVICE_DATA_ITEM";
        return false;
    }

    inputDataItemsList.replace(folderRow, IDFServiceInputDataItem(folderPath, processSubpath));

    currentInputData.setInputDataList(inputDataItemsList);

    m_dataWarehouse.setInputData(currentInputData);

    return true;
}

bool IDFServiceController::removeInputFolder(const int folderRow) {
    IDFServiceInputData currentInputData = m_dataWarehouse.getInputData();

    QList<IDFServiceInputDataItem> inputDataItemsList = currentInputData.getInputDataList();
    if (folderRow < 0 || folderRow >= inputDataItemsList.size()) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_REMOVE_SERVICE_DATA_ITEM";
        return false;
    }

    inputDataItemsList.removeAt(folderRow);

    currentInputData.setInputDataList(inputDataItemsList);

    m_dataWarehouse.setInputData(currentInputData);

    return true;
}

DuplicateItemsGroups IDFServiceController::getDuplicateItemsGroups() const {
    return m_dataWarehouse.getModelDuplicatesGroups();
}

void IDFServiceController::onServiceStarted() {
    emit serviceStarted();
}

void IDFServiceController::onServiceInterrupted() {
    emit serviceInterrupted();
}

void IDFServiceController::onServiceFinished() {
    auto modelDuplicatesGroups = m_dataConvertor.toDuplicateItemsGroups(m_idfService.getOutputData());

    m_dataWarehouse.setModelDuplicatesGroups(modelDuplicatesGroups);

    emit serviceFinished();
}

void IDFServiceController::onPublishProgress(OperationProgress value) {
    m_currentOperationProgress = value;

    emit currentServiceOperationNameChanged(getCurrentServiceOperationName());
    emit currentServiceOperationProgressChanged(getCurrentServiceOperationProgress());
}

//void IDFServiceController::onServiceFinished() {
//    auto modelDuplicatesGroups = m_dataConvertor.toDuplicateItemsGroups(m_idfService.getOutputData());
//    auto modelDuplicatesGroupsList = modelDuplicatesGroups.getGroupsList();

//    for (int i = 0; i < modelDuplicatesGroupsList.size(); ++i) {
//        auto group = modelDuplicatesGroupsList.at(i);
//        auto groupDuplicatesList = group.getDuplicateItemsList();

//        for (int j = 0; j < groupDuplicatesList.size(); ++j) {
//            auto duplicate = groupDuplicatesList.at(j);

//            qDebug() << duplicate.getImagePath();
//        }

//        qDebug() << "";
//    }

//    m_dataWarehouse.setModelDuplicatesGroups(modelDuplicatesGroups);

//    emit serviceFinished();
//}
