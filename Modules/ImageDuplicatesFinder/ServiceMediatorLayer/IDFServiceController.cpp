#include "IDFServiceController.h"



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

void IDFServiceController::onServiceStarted() {
    emit serviceStarted();
}

void IDFServiceController::onServiceInterrupted() {
    emit serviceInterrupted();
}

void IDFServiceController::onServiceFinished() {
    emit serviceFinished();
}
