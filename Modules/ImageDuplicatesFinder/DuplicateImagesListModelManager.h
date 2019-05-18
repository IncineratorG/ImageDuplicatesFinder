#ifndef DUPLICATEIMAGESLISTMODELMANAGER_H
#define DUPLICATEIMAGESLISTMODELMANAGER_H

#include <QObject>
#include "Services/ImageDuplicatesFinderService/IDFService.h"



class DuplicateImagesListModelManager : public QObject
{
    Q_OBJECT

public:
    DuplicateImagesListModelManager();

public slots:
    void start();
    void stop();

private slots:
    void onImageDuplicatesFinderServiceStarted();
    void onImageDuplicatesFinderServiceInterrupted();
    void onImageDuplicatesFinderServiceFinished();

private:
    IDFService idfService;
};

#endif // DUPLICATEIMAGESLISTMODELMANAGER_H
