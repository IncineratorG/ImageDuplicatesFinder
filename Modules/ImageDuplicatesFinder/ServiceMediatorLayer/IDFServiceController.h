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

    Q_PROPERTY(QString serviceStatus                   READ getServiceStatus                   NOTIFY serviceStatusChanged)
    Q_PROPERTY(QString currentServiceOperationName     READ getCurrentServiceOperationName     NOTIFY currentServiceOperationNameChanged)
    Q_PROPERTY(QString currentServiceOperationProgress READ getCurrentServiceOperationProgress NOTIFY currentServiceOperationProgressChanged)

public:
    static IDFServiceController* getInstance();

    void startService();
    void stopService();

    QString getServiceStatus() const;
    QString getCurrentServiceOperationName() const;
    QString getCurrentServiceOperationProgress() const;

    IDFServiceInputData getInputData() const;

    void addInputFolder(const QString& folderPath, const bool processSubpath);
    bool updateInputFolder(const int folderRow, const QString& folderPath, const bool processSubpath);
    bool removeInputFolder(const int folderRow);

    DuplicateItemsGroups getDuplicateItemsGroups() const;

    DuplicateItemsGroup getDuplicateItemGroup(const qint64 groupId) const;

    bool removeDuplicateItem(const qint64 itemId);

signals:
    void serviceStarted();
    void serviceInterrupted();
    void serviceFinished();

    void serviceStatusChanged(QString value);
    void currentServiceOperationNameChanged(QString value);
    void currentServiceOperationProgressChanged(QString value);

    void duplciateItemRemoved(qint64 itemId);

private slots:
    void onServiceStarted();
    void onServiceInterrupted();
    void onServiceFinished();

    void onPublishProgress(OperationProgress value);

private:
    static IDFServiceController* m_instance;

    IDFService m_idfService;
    IDFServiceDataWarehouse m_dataWarehouse;
    IDFServiceDataConvertor m_dataConvertor;

    OperationProgress m_currentOperationProgress;

    IDFServiceController();
};

#endif // IDFSERVICECONTROLLER_H
