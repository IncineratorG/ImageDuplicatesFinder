#ifndef IDFSERVICECONTROLLER_H
#define IDFSERVICECONTROLLER_H

#include <QObject>
#include "IDFServiceDataWarehouse.h"
#include "Services/ImageDuplicatesFinderService/IDFService.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h"



class IDFServiceController : public QObject
{
    Q_OBJECT

public:
    static IDFServiceController* getInstance();

    void startService();
    void stopService();

    IDFServiceInputData getInputData() const;

    void addInputFolder(const QString& folderPath, const bool processSubpath);
    bool updateInputFolder(const int folderRow, const QString& folderPath, const bool processSubpath);
    bool removeInputFolder(const int folderRow);

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
    IDFServiceDataWarehouse m_dataWarehouse;

    IDFServiceController();
};

#endif // IDFSERVICECONTROLLER_H
