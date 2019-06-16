#include "InputFoldersModelManager.h"
#include <QDebug>

// ===
//#include "../../../Services/ImageDuplicatesFinderService/Data/ImageHistogram.h"
// ===



InputFoldersModelManager::InputFoldersModelManager(InputFoldersModel* inputFoldersModel)
    : m_inputFoldersModel(inputFoldersModel),
      QML_FOLDER_PREFIX("file:///")
{
    m_idfServiceController = IDFServiceController::getInstance();
}

void InputFoldersModelManager::addFolder(const QString& folderPath) {
    QString validFolderPath = folderPath;
    if (validFolderPath.contains(QML_FOLDER_PREFIX)) {
        validFolderPath.remove(0, QML_FOLDER_PREFIX.length());
    }

    InputFolderItem modelItem(validFolderPath, true);

    // Добавляем новые данные для обработки в контроллер сервиса.
    bool itemAdded = m_idfServiceController->addInputFolder(modelItem.getPath(), modelItem.getProcessSubpath());

    // Добавляем новые данные в модель.
    if (itemAdded) {
        m_inputFoldersModel->addFolder(modelItem);
    }
}

void InputFoldersModelManager::setProcessSubfolders(const int folderRow, const bool process) {
    QString folderPath = m_inputFoldersModel->data(m_inputFoldersModel->index(folderRow, 0), InputFoldersModel::FolderPathRole).toString();

    InputFolderItem modelItem(folderPath, process);

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

//void InputFoldersModelManager::startProcessing() {
//    qDebug() << __PRETTY_FUNCTION__;

//    QString image_1 = "C:/Users/Alexander/Downloads/TEST_IMAGES/Chrysanthemum.jpg";
//    QString image_2 = "C:/Users/Alexander/Downloads/TEST_IMAGES/IMAGES/TEST_IMAGES/Chrysanthemum.jpg";

//    ImageHistogram hist_1(image_1);
//    ImageHistogram hist_2(image_2);

//    qDebug() << __PRETTY_FUNCTION__ << "->" << hist_1.similarityScore(hist_2);
////    qDebug() << __PRETTY_FUNCTION__ << "->" << hist_2.similarityScore(hist_1);
//}
void InputFoldersModelManager::startProcessing() {
    qDebug() << __PRETTY_FUNCTION__;

    m_idfServiceController->startService();
}

void InputFoldersModelManager::stopProcessing() {
    qDebug() << __PRETTY_FUNCTION__;

    m_idfServiceController->stopService();
}
