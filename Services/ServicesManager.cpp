#include "ServicesManager.h"
#include "Services/ImageDuplicatesFinderService/IDFService.h"



ServicesManager* ServicesManager::m_instance = nullptr;

ServicesManager* ServicesManager::getInstance() {
    if (!m_instance) {
        m_instance = new ServicesManager();
    }

    return m_instance;
}

ServicesManager::ServicesManager() {
    m_servicesMap.insert(ServiceType::ImageDuplicatesFinder, new IDFService());
}

AbstractService* ServicesManager::getService(ServiceType serviceType) {
    switch (serviceType) {
        case ImageDuplicatesFinder:
            return m_servicesMap.value(ImageDuplicatesFinder);
    }

    return nullptr;
}
