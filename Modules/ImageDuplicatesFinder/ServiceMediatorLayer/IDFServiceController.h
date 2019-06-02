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

    // Запускает сервис поиска дубликатов изображений.
    void startService();
    // Останавливает сервис.
    void stopService();

    // Получить текущий статус сервиса поиска дубликатов.
    QString getServiceStatus() const;
    // Получить наименование текущей выполняющейся операции сервиса.
    QString getCurrentServiceOperationName() const;
    // Получить прогресс текущей операции серивса.
    QString getCurrentServiceOperationProgress() const;

    // Получить текущие входные данные сервиса.
    IDFServiceInputData getInputData() const;

    // Добавить папку во входные данные сервиса.
    void addInputFolder(const QString& folderPath, const bool processSubpath);
    // Обновить папку входных данных сервиса.
    bool updateInputFolder(const int folderRow, const QString& folderPath, const bool processSubpath);
    // Удалить из входных данных соответсвующую папку.
    bool removeInputFolder(const int folderRow);

    // Получить группы дубликатов изображений.
    DuplicateItemsGroups getDuplicateItemsGroups() const;

    // Получить группу дубликатов одного изображения с соответствующим ID.
    DuplicateItemsGroup getDuplicateItemGroup(const qint64 groupId) const;

    // Удалить один дубликат изображения с соответсвующим ID.
    bool removeDuplicateItem(const qint64 itemId);

signals:
    void serviceStarted();
    void serviceInterrupted();
    void serviceFinished();

    void serviceStatusChanged(QString value);
    void currentServiceOperationNameChanged(QString value);
    void currentServiceOperationProgressChanged(QString value);

    void duplciateItemRemoved(qint64 groupId, qint64 itemId);

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
