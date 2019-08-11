#include "AbstractStorage.h"



AbstractStorage::~AbstractStorage() {

}

std::shared_ptr<AbstractStore> AbstractStorage::getStore() {
    return nullptr;
}
