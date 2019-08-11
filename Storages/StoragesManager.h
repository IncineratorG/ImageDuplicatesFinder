#ifndef STORAGESMANAGER_H
#define STORAGESMANAGER_H

#include "Abstract/AbstractStorage.h"



class StoragesManager
{
public:
    enum StorageType {
        ImageDuplicatesFinder
    };

    static StoragesManager* getInstance();

    AbstractStorage* getStorage(StorageType storageType);

private:
    static StoragesManager* m_instance;

    StoragesManager();
};

#endif // STORAGESMANAGER_H
