#include "IDFStorage.h"
#include "IDFStore.h"



IDFStorage* IDFStorage::m_instance = nullptr;

IDFStorage* IDFStorage::getInstance() {
    if (!m_instance) {
        m_instance = new IDFStorage();
    }

    return m_instance;
}

IDFStorage::IDFStorage() {
    m_idfStore = std::shared_ptr<IDFStore>(new IDFStore());
}

void IDFStorage::executeAction(std::shared_ptr<AbstractAction> action) {
    if (action == nullptr) {
        return;
    }

    action->execute();
}

std::shared_ptr<AbstractStore> IDFStorage::getStore() {
    return m_idfStore;
}
