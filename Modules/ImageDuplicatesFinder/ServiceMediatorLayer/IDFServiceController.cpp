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

bool IDFServiceController::addInputFolder(const QString& folderPath, const bool processSubpath) {
    IDFServiceInputData currentInputData = m_dataWarehouse.getInputData();
    if (currentInputData.containInputDataItem(IDFServiceInputDataItem(folderPath, processSubpath))) {
        return false;
    }

    currentInputData.appendInputDataItem(IDFServiceInputDataItem(folderPath, processSubpath));

    m_dataWarehouse.setInputData(currentInputData);

    return true;
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

DuplicateItemsGroup IDFServiceController::getDuplicateItemGroup(const qint64 groupId) const {
    return m_dataWarehouse.getModelDuplicateItemGroup(groupId);
}

bool IDFServiceController::removeDuplicateItem(const qint64 itemId) {
    // Получаем список групп дубликатов всех изображений.
    auto duplicatesGroups = m_dataWarehouse.getModelDuplicatesGroups();
    auto groupsList = duplicatesGroups.getGroupsList();

    // Проходимся по всем группам дубликатов и ищем группу,
    // содержащую дубликат с соответсвующим ID.
    qint64 containingGroupId = -1;
    for (int i = 0; i < groupsList.size(); ++i) {
        DuplicateItemsGroup& group = groupsList[i];

        // Удаляем дубликат с заданным ID из соответсвующей группы.
        if (group.contains(itemId)) {
            group.removeDuplicateById(itemId);

            containingGroupId = group.getId();

            // Если в группе остался только один
            // элемент - удаляем эту группу из списка.
            if (group.getGroupSize() <= 1) {
                groupsList.removeAt(i);
            }

            break;
        }
    }

    if (containingGroupId < 0) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_REMOVE_DUPLICATE_WITH_ID: " << itemId;
        return false;
    }

    DuplicateItemsGroups editedGroups(groupsList);

    m_dataWarehouse.setModelDuplicatesGroups(editedGroups);

    emit duplciateItemRemoved(containingGroupId, itemId);

    return true;
}
//bool IDFServiceController::removeDuplicateItem(const qint64 itemId) {
//    // Получаем список групп дубликатов всех изображений.
//    auto duplicatesGroups = m_dataWarehouse.getModelDuplicatesGroups();
//    QList<DuplicateItemsGroup> groupsList = duplicatesGroups.getGroupsList();

////     Проходимся по всем группам дубликатов и ищем группу,
////     содержащую дубликат с соответсвующим ID.
//    qint64 containingGroupId = -1;
//    for (int i = 0; i < groupsList.size(); ++i) {
//        DuplicateItemsGroup& group = groupsList[i];

//        // Удаляем дубликат с заданным ID из соответсвующей группы.
//        if (group.contains(itemId)) {
//            group.removeDuplicateById(itemId);

//            containingGroupId = group.getId();

//            break;
//        }
//    }

//    if (containingGroupId < 0) {
//        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_REMOVE_DUPLICATE_WITH_ID: " << itemId;
//        return false;
//    }

//    DuplicateItemsGroups editedGroups(groupsList);

//    m_dataWarehouse.setModelDuplicatesGroups(editedGroups);

//    emit duplciateItemRemoved(containingGroupId, itemId);

//    return true;
//}

void IDFServiceController::onServiceStarted() {
    emit serviceStarted();
}

void IDFServiceController::onServiceInterrupted() {
    emit serviceInterrupted();
}

void IDFServiceController::onServiceFinished() {
    int a = 1 + 2;

    m_dataConvertor.convertAndSave(m_idfService.getOutputData(), &m_dataWarehouse);

    emit serviceFinished();
}
//void IDFServiceController::onServiceFinished() {
//    auto modelDuplicatesGroups = m_dataConvertor.toDuplicateItemsGroups(m_idfService.getOutputData());
//    m_dataConvertor.toFoldersInfos(m_idfService.getOutputData());

//    m_dataWarehouse.setModelDuplicatesGroups(modelDuplicatesGroups);

//    emit serviceFinished();
//}

void IDFServiceController::onPublishProgress(OperationProgress value) {
    m_currentOperationProgress = value;

    emit currentServiceOperationNameChanged(getCurrentServiceOperationName());
    emit currentServiceOperationProgressChanged(getCurrentServiceOperationProgress());
}
