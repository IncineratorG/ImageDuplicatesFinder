#include "IDFServiceController.h"
#include <QDebug>



IDFServiceController* IDFServiceController::m_instance = nullptr;

IDFServiceController* IDFServiceController::getInstance() {
    if (!m_instance)
        m_instance = new IDFServiceController();

    return m_instance;
}

IDFServiceController::IDFServiceController() {
    connect(&m_idfService, SIGNAL(started()), this, SLOT(onServiceStarted()));
    connect(&m_idfService, SIGNAL(interrupted()), this, SLOT(onServiceInterrupted()));
    connect(&m_idfService, SIGNAL(finished()), this, SLOT(onServiceFinished()));
}

void IDFServiceController::startService(const IDFServiceInputData& inputData) {
    m_idfService.start(inputData);
}

void IDFServiceController::stopService() {
    m_idfService.stop();
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

void IDFServiceController::onServiceStarted() {
    emit serviceStarted();
}

void IDFServiceController::onServiceInterrupted() {
    emit serviceInterrupted();
}

void IDFServiceController::onServiceFinished() {
    emit serviceFinished();
}
