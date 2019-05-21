#ifndef INPUTFOLDERSMODELMANAGER_H
#define INPUTFOLDERSMODELMANAGER_H

#include <QObject>
#include "InputFoldersModel.h"
#include "../ServiceMediatorLayer/IDFServiceController.h"



class InputFoldersModelManager : public QObject
{
    Q_OBJECT

public:
    InputFoldersModelManager(InputFoldersModel* inputFoldersModel);

public slots:
    void addFolder(const QString& folderPath);
    void setProcessSubfolders(const int folderRow, const bool process);
    void removeFolder(const int folderRow);

    void startProcessing();

private:
    InputFoldersModel* m_inputFoldersModel;
    IDFServiceController* m_idfServiceController;

    const QString QML_FOLDER_PREFIX;
};

#endif // INPUTFOLDERSMODELMANAGER_H
