#ifndef SERVICESMANAGER_H
#define SERVICESMANAGER_H

#include "Services/ImageDuplicatesFinderService/Abstract/AbstractService.h"
#include <QMap>



class ServicesManager
{
public:
    enum ServiceType {
        ImageDuplicatesFinder
    };

    static ServicesManager* getInstance();

    AbstractService* getService(ServiceType serviceType);

private:
    static ServicesManager* m_instance;

    QMap<ServiceType, AbstractService*> m_servicesMap;

    ServicesManager();
};

#endif // SERVICESMANAGER_H
