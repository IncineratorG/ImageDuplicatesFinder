#ifndef ABSTRACTSTORAGE_H
#define ABSTRACTSTORAGE_H

#include "AbstractAction.h"
#include "AbstractStore.h"
#include "memory"



class AbstractStorage
{
public:
    virtual ~AbstractStorage() = 0;

    virtual void executeAction(std::shared_ptr<AbstractAction> action) = 0;
    virtual std::shared_ptr<AbstractStore> getStore();
};

#endif // ABSTRACTSTORAGE_H
