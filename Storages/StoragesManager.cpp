#include "StoragesManager.h"
#include "ImageDuplicatesFinder/IDFStorage.h"



StoragesManager* StoragesManager::m_instance = nullptr;

StoragesManager* StoragesManager::getInstance() {
    if (!m_instance) {
        m_instance = new StoragesManager();
    }

    return m_instance;
}

StoragesManager::StoragesManager() {

}

AbstractStorage* StoragesManager::getStorage(StorageType storageType) {
    switch (storageType) {
        case ImageDuplicatesFinder:
            return IDFStorage::getInstance();
    }

    return nullptr;
}
