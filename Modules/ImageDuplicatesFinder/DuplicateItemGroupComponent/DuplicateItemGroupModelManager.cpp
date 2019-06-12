#include "DuplicateItemGroupModelManager.h"
#include <QProcess>
#include <QDebug>



DuplicateItemGroupModelManager::DuplicateItemGroupModelManager(DuplicateItemGroupModel* duplicateGroupModel)
    : m_duplicateGroupModel(duplicateGroupModel)
{
    m_idfServiceController = IDFServiceController::getInstance();

    connect(m_idfServiceController, SIGNAL(duplciateItemRemoved(qint64, qint64)), this, SLOT(onDuplicateItemRemoved(qint64, qint64)));
}

void DuplicateItemGroupModelManager::loadDuplicateGroup(const int groupId) {
    const DuplicateItemsGroup& group = m_idfServiceController->getDuplicateItemGroup(groupId);

    m_duplicateGroupModel->fillModel(group);

    disconnectFileWatcher();
}

void DuplicateItemGroupModelManager::setGeneralImageItem(const qint64 itemId) {
    // Находим в модели элемент с заданным ID.
    auto modelIndexesList = m_duplicateGroupModel->match(
                                        m_duplicateGroupModel->index(0, 0),
                                        DuplicateItemGroupModel::IDRole,
                                        itemId);
    if (modelIndexesList.size() <= 0) {
        return;
    }

    const QModelIndex& matchedItemIndex = modelIndexesList.at(0);

    const QString& itemPath = m_duplicateGroupModel->data(matchedItemIndex, DuplicateItemGroupModel::DuplicateImagePathRole).toString();

    // Устанавливаем обощенное изображение группы дубликатов.
    m_duplicateGroupModel->setGeneralImagePath(itemPath);
}

void DuplicateItemGroupModelManager::openItemPath(const qint64 itemId) {
    // Находим в модели элемент с заданным ID.
    auto modelIndexesList = m_duplicateGroupModel->match(
                                        m_duplicateGroupModel->index(0, 0),
                                        DuplicateItemGroupModel::IDRole,
                                        itemId);
    if (modelIndexesList.size() <= 0) {
        return;
    }

    const QModelIndex& matchedItemIndex = modelIndexesList.at(0);

    const QString& itemPath = m_duplicateGroupModel->data(matchedItemIndex, DuplicateItemGroupModel::DuplicateImagePathRole).toString();

    // Если файла по такому пути не существует - ничего не делаем.
    QFileInfo fileInfo(itemPath);
    if (!fileInfo.exists()) {
        qDebug() << __PRETTY_FUNCTION__ << "->PATH: " << itemPath << " NOT_EXIST";
        return;
    }

    // Открываем файл в сдандартном системном просмотрщике файлов.
    QStringList args;
    args << "/select," << QDir::toNativeSeparators(itemPath);
    QProcess::startDetached("explorer", args);

    // Слушаем изменения данного файла.
    m_fileSystemWatcher.addPath(itemPath);
    connect(&m_fileSystemWatcher, SIGNAL(fileChanged(const QString&)), this, SLOT(onFileChanged(const QString&)));
}

void DuplicateItemGroupModelManager::markItemAsNotDuplicate(const qint64 itemId) {
    // Удаляем элемент из хранилища данных
    m_idfServiceController->removeDuplicateItem(itemId);
}

void DuplicateItemGroupModelManager::removeItemFromDisk(const qint64 itemId) {
    // Получаем путь до соответсвующего файла с изображением.
    const QString filePath = m_duplicateGroupModel->getItemImagePathText(itemId);
    if (filePath.isEmpty()) {
        qDebug() << __PRETTY_FUNCTION__ << "->NO_ITEM_WITH_ID: " << itemId;
        return;
    }

    // Удаляем файл с диска.
    QFile fileToRemove(filePath);
    if (!fileToRemove.exists()) {
        qDebug() << __PRETTY_FUNCTION__ << "->NO_SUCH_FILE: " << filePath;
        return;
    }

    bool fileRemovedFromDisk = fileToRemove.remove();
    if (!fileRemovedFromDisk) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_REMOVE_FILE: " << filePath;
        return;
    }

    // Удаляем элемент из хранилища данных.
    bool itemRemovedFromWarehouse = m_idfServiceController->removeDuplicateItem(itemId);
    if (!itemRemovedFromWarehouse) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNABLE_TO_REMOVE_ITEM_FROM_WAREHOUSE: " << itemId;
    }
}

void DuplicateItemGroupModelManager::stopListenToFileChangies() {
    disconnectFileWatcher();
}

QString DuplicateItemGroupModelManager::getItemImagePath(const qint64 itemId) const {
    return m_duplicateGroupModel->getItemImagePath(itemId);
}

QString DuplicateItemGroupModelManager::getItemImagePathText(const qint64 itemId) const {
    return m_duplicateGroupModel->getItemImagePathText(itemId);
}

void DuplicateItemGroupModelManager::onFileChanged(const QString& path) {
    QFileInfo fileInfo(path);
    if (fileInfo.exists()) {
        return;
    }

    // Перестаём слушать события изменения данного файла.
    m_fileSystemWatcher.removePath(path);

    // Получаем ID удалённого дубликата.
    const qint64 duplicateItemId = m_duplicateGroupModel->getItemIdByImagePath(path);
    if (duplicateItemId < 0) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_DUPLICATE_ITEM_ID; IMAGE_PATH: " << path << "; ID: " << duplicateItemId;
    }

    // Удаляем соответсвующий элемент из модели.
    m_duplicateGroupModel->removeItem(duplicateItemId);

    // Удаляем дубликат из хранилища данных сервиса.
    m_idfServiceController->removeDuplicateItem(duplicateItemId);

    if (m_fileSystemWatcher.directories().size() <= 0) {
        disconnect(&m_fileSystemWatcher, nullptr, nullptr, nullptr);
    }
}

void DuplicateItemGroupModelManager::onDuplicateItemRemoved(qint64 groupId, qint64 itemId) {
    // Удаляем соответсвующий элемент из модели.
    m_duplicateGroupModel->removeItem(itemId);
}

void DuplicateItemGroupModelManager::disconnectFileWatcher() {
    if (m_fileSystemWatcher.directories().size() > 0) {
        m_fileSystemWatcher.removePaths(m_fileSystemWatcher.directories());
        disconnect(&m_fileSystemWatcher, nullptr, nullptr, nullptr);
    }
}
