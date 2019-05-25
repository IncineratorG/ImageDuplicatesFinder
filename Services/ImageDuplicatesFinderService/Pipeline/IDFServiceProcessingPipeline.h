#ifndef IDFSERVICEPROCESSINGPIPELINE_H
#define IDFSERVICEPROCESSINGPIPELINE_H

#include <QObject>
#include <QThread>
#include <memory>
#include <functional>
#include "../Data/IDFServiceInputData.h"
#include "../Data/IDFServiceOutputData.h"
#include "../InputPathsPreparator/AbstractInputPathsPreparator.h"
#include "../ImagesPathsFinder/AbstractImagesPathsFinder.h"
#include "../ImagesHistogramsBuilder/AbstractImagesHistogramsBuilder.h"
#include "../HistogramsComparator/AbstractHistogramsComparator.h"
#include "AbstractOperation.h"
#include "PipelineOperationsTransitions.h"



class IDFServiceProcessingPipeline : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString status READ getStatus WRITE setStatus NOTIFY statusChanged)

public:
    enum Status {
        PROCESSING, IDLE
    };

    IDFServiceProcessingPipeline();
    ~IDFServiceProcessingPipeline();

    QString getStatus() const;
    Status getStatusEnum() const;

    void setStatus(QString value);
    void setStatus(const Status status);

public slots:
    // Устанавливаем входные данные конвейера.
    void setInputData(const IDFServiceInputData& inputData);

    // Запускает конвейер.
    void startPipeline();
    // Прерывает конвейер.
    void interruptPipeline();

signals:
    void pipelineStarted();
    void pipelineInterrupted();
    void pipelineFinished(IDFServiceOutputData outputData);

    void statusChanged(QString value);

private slots:
    // Действия, выполняемые при завершении работы каждой операции конвейера.
    void onOperationFinished();

private:
    QString m_statusString;
    Status m_statusEnum;
    QMap<QString, Status> m_statusesMap;

    bool m_pipelineInterrupted;

    IDFServiceInputData m_inputData;
    Paths m_inputPaths;

    AbstractOperation* m_currentOperation;
    AbstractInputPathsPreparator* m_inputPathsPreparatorOperation;
    AbstractImagesPathsFinder* m_imagesPathsFinderOperation;
    AbstractImagesHistogramsBuilder* m_histogramsBuilderOperation;
    AbstractHistogramsComparator* m_histogramsComparatorOperation;

    PipelineOperationsTransitions m_operationsTransitions;


    // Устанавливает действия, которые необходимо
    // выполнять при переходе от одной операции к другой.
    void setOperationsTransitions();

    // Действия, выполняемые при запуске конвейера.
    void doWork();

    // Запускает следующую по очереди операцию конвейера.
    void runNextOperation();
};

#endif // IDFSERVICEPROCESSINGPIPELINE_H
