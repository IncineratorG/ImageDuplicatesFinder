#ifndef IDFSERVICECONTROLLER_H
#define IDFSERVICECONTROLLER_H

#include <QObject>
#include "Services/ImageDuplicatesFinderService/IDFService.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h"



class IDFServiceController : public QObject
{
    Q_OBJECT

public:
    static IDFServiceController* getInstance();

    void startService(const IDFServiceInputData& inputData);
    void stopService();

signals:
    void serviceStarted();
    void serviceInterrupted();
    void serviceFinished();

private slots:
    void onServiceStarted();
    void onServiceInterrupted();
    void onServiceFinished();

private:
    static IDFServiceController* m_instance;

    IDFService m_idfService;

    IDFServiceController();
};

#endif // IDFSERVICECONTROLLER_H
