#include "DuplicateItemGroupModelManager.h"
#include <QProcess>
#include <QDebug>



DuplicateItemGroupModelManager::DuplicateItemGroupModelManager(DuplicateItemGroupModel* duplicateGroupModel)
    : m_duplicateGroupModel(duplicateGroupModel)
{
    m_idfServiceController = IDFServiceController::getInstance();
}

void DuplicateItemGroupModelManager::loadDuplicateGroup(const int groupId) {
    const DuplicateItemsGroup& group = m_idfServiceController->getDuplicateItemGroup(groupId);

    m_duplicateGroupModel->fillModel(group);
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
    QFileInfo inputFileInfo(itemPath);
    if (!inputFileInfo.exists()) {
        qDebug() << __PRETTY_FUNCTION__ << "->PATH: " << itemPath << " NOT_EXIST";
        return;
    }

    // Открываем файл в сдандартном системном просмотрщике файлов.
    QStringList args;
    args << "/select," << QDir::toNativeSeparators(itemPath);
    QProcess::startDetached("explorer", args);

    // Слушаем изменения данного файла.
    if (m_fileSystemWatcher.directories().size() > 0) {
        m_fileSystemWatcher.removePaths(m_fileSystemWatcher.directories());
        disconnect(&m_fileSystemWatcher, nullptr, nullptr, nullptr);
    }

    m_fileSystemWatcher.addPath(itemPath);
    connect(&m_fileSystemWatcher, SIGNAL(fileChanged(const QString&)), this, SLOT(onFileChanged(const QString&)));
}

void DuplicateItemGroupModelManager::stopListenToFileChangies() {
    if (m_fileSystemWatcher.directories().size() > 0) {
        m_fileSystemWatcher.removePaths(m_fileSystemWatcher.directories());
        disconnect(&m_fileSystemWatcher, nullptr, nullptr, nullptr);
    }
}

void DuplicateItemGroupModelManager::onFileChanged(const QString& path) {
    QFileInfo inputFileInfo(path);
    if (!inputFileInfo.exists()) {
        qDebug() << __PRETTY_FUNCTION__ << "->PATH: " << path << " NOT_EXIST";
    } else {
        qDebug() << __PRETTY_FUNCTION__ << "->PATH: " << path << " EXIST";
    }
}
