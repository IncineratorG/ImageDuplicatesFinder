#include "InputFoldersModelManager.h"
#include <QDebug>



InputFoldersModelManager::InputFoldersModelManager(InputFoldersModel* inputFoldersModel)
    : m_inputFoldersModel(inputFoldersModel)
{
    m_idfServiceController = IDFServiceController::getInstance();
}

void InputFoldersModelManager::addFolder(const QString& folderPath) {
    InputFoldersModelItem modelItem(folderPath, false);

    // Добавляем новые данные для обработки в контроллер сервиса.
    m_idfServiceController->addInputFolder(modelItem.getPath(), modelItem.getProcessSubpath());

    // Добавляем новые данные в модель.
    m_inputFoldersModel->addFolder(modelItem);
}

void InputFoldersModelManager::setProcessSubfolders(const int folderRow, const bool process) {
    QString folderPath = m_inputFoldersModel->data(m_inputFoldersModel->index(folderRow, 0), InputFoldersModel::FolderPathRole).toString();

    InputFoldersModelItem modelItem(folderPath, process);

    // Обновляем данные в контроллере сервиса.
    bool updatedSuccessfully = m_idfServiceController->updateInputFolder(folderRow, modelItem.getPath(), modelItem.getProcessSubpath());
    if (!updatedSuccessfully) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_UPDATE_SERVICE_DATA_ITEM";
        return;
    }

    // Обновляем модель.
    m_inputFoldersModel->updateFolder(folderRow, modelItem);
}

void InputFoldersModelManager::removeFolder(const int folderRow) {
    // Удаляем данные из контроллера сервиса.
    bool removedSuccessfully = m_idfServiceController->removeInputFolder(folderRow);
    if (!removedSuccessfully) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_REMOVE_SERVICE_DATA_ITEM";
        return;
    }

    // Удаляем данные из модели.
    m_inputFoldersModel->removeFolder(folderRow);
}

void InputFoldersModelManager::startProcessing() {
    qDebug() << __PRETTY_FUNCTION__;

    m_idfServiceController->startService();
}
