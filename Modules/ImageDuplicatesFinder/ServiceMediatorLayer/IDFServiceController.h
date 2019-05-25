#ifndef IDFSERVICECONTROLLER_H
#define IDFSERVICECONTROLLER_H

#include <QObject>
#include "IDFServiceDataWarehouse.h"
#include "IDFServiceDataConvertor.h"
#include "Services/ImageDuplicatesFinderService/IDFService.h"
#include "Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h"



class IDFServiceController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString serviceStatus READ getServiceStatus NOTIFY serviceStatusChanged)

public:
    static IDFServiceController* getInstance();

    void startService();
    void stopService();

    QString getServiceStatus() const;

    IDFServiceInputData getInputData() const;

    void addInputFolder(const QString& folderPath, const bool processSubpath);
    bool updateInputFolder(const int folderRow, const QString& folderPath, const bool processSubpath);
    bool removeInputFolder(const int folderRow);

    DuplicateItemsGroups getDuplicateItemsGroups() const;

signals:
    void serviceStarted();
    void serviceInterrupted();
    void serviceFinished();

    void serviceStatusChanged(QString value);

private slots:
    void onServiceStarted();
    void onServiceInterrupted();
    void onServiceFinished();

private:
    static IDFServiceController* m_instance;

    IDFService m_idfService;
    IDFServiceDataWarehouse m_dataWarehouse;
    IDFServiceDataConvertor m_dataConvertor;

    IDFServiceController();
};

#endif // IDFSERVICECONTROLLER_H
