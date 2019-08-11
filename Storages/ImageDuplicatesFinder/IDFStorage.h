#ifndef IDFSTORAGE_H
#define IDFSTORAGE_H

#include "Storages/Abstract/AbstractStorage.h"
#include "IDFStore.h"



class IDFStorage : public AbstractStorage
{
public:
    static IDFStorage* getInstance();

    void executeAction(std::shared_ptr<AbstractAction> action);
    std::shared_ptr<AbstractStore> getStore();

private:
    static IDFStorage* m_instance;

    std::shared_ptr<IDFStore> m_idfStore;

    IDFStorage();
};

#endif // IDFSTORAGE_H
