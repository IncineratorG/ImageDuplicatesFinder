#include "IDFServiceProcessingPipeline.h"
#include "../InputPathsPreparator/SequetialInputPathsPreparator.h"
#include "../ImagesPathsFinder/SequentialImagesPathsFinder.h"
#include "../ImagesHistogramsBuilder/SequentialImagesHistogramsBuilder.h"
#include "../HistogramsComparator/SequentialHistogramsComparator.h"
#include <QDir>
#include <QDebug>



IDFServiceProcessingPipeline::IDFServiceProcessingPipeline()
    : m_pipelineInterrupted(false),
      m_currentOperation(nullptr),
      m_imagesPathsFinderOperation(nullptr)
{
    m_statusesMap.insert("processing", PROCESSING);
    m_statusesMap.insert("idle", IDLE);

    setStatus("idle");

    // Инициализируем операции конвейера.
    m_inputPathsPreparatorOperation = new SequetialInputPathsPreparator();
    m_imagesPathsFinderOperation = new SequentialImagesPathsFinder();
    m_histogramsBuilderOperation = new SequentialImagesHistogramsBuilder();
    m_histogramsComparatorOperation = new SequentialHistogramsComparator();

    // Создаём последовательность операций.
    m_inputPathsPreparatorOperation->setNextOperation(m_imagesPathsFinderOperation);
    m_imagesPathsFinderOperation->setNextOperation(m_histogramsBuilderOperation);
    m_histogramsBuilderOperation->setNextOperation(m_histogramsComparatorOperation);
    m_histogramsComparatorOperation->setNextOperation(nullptr);

    // Устанавливаем действия, которые необходимо
    // выполнять при переходе от одной операции к другой.
    setOperationsTransitions();
}

IDFServiceProcessingPipeline::~IDFServiceProcessingPipeline() {
    m_currentOperation = nullptr;

    if (m_imagesPathsFinderOperation != nullptr) {
        m_imagesPathsFinderOperation->quit();
    }
    if (m_histogramsBuilderOperation != nullptr) {
        m_histogramsBuilderOperation->quit();
    }
    if (m_histogramsComparatorOperation != nullptr) {
        m_histogramsComparatorOperation->quit();
    }

    if (m_imagesPathsFinderOperation != nullptr) {
        m_imagesPathsFinderOperation->wait();
    }
    if (m_histogramsBuilderOperation != nullptr) {
        m_histogramsBuilderOperation->wait();
    }
    if (m_histogramsComparatorOperation != nullptr) {
        m_histogramsComparatorOperation->wait();
    }
}

QString IDFServiceProcessingPipeline::getStatus() const {
    return m_statusString;
}

IDFServiceProcessingPipeline::Status IDFServiceProcessingPipeline::getStatusEnum() const {
    return m_statusEnum;
}

void IDFServiceProcessingPipeline::setStatus(QString value) {
    if (!m_statusesMap.contains(value)) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_STATUS: " << value << "; CURRENT_STATUS: " << getStatus();
        return;
    }

    m_statusString = value;
    m_statusEnum = m_statusesMap.value(m_statusString);

    emit statusChanged(getStatus());
}

void IDFServiceProcessingPipeline::setStatus(const IDFServiceProcessingPipeline::Status status) {
    if (!m_statusesMap.values().contains(status)) {
        qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_STATUS: " << status << "; CURRENT_STATUS: " << getStatus();
        return;
    }

    m_statusEnum = status;
    m_statusString = m_statusesMap.key(status);

    emit statusChanged(getStatus());
}

void IDFServiceProcessingPipeline::setInputData(const IDFServiceInputData& inputData) {
    qDebug() << __PRETTY_FUNCTION__;

    m_inputData = inputData;
}

void IDFServiceProcessingPipeline::startPipeline() {
    qDebug() << __PRETTY_FUNCTION__;

    m_pipelineInterrupted = false;

    setStatus(PROCESSING);

    emit pipelineStarted();

    doWork();
}

void IDFServiceProcessingPipeline::interruptPipeline() {
    qDebug() << __PRETTY_FUNCTION__;

    m_pipelineInterrupted = true;

    if (m_currentOperation != nullptr) {
        m_currentOperation->requestInterruption();
    }
}

void IDFServiceProcessingPipeline::doWork() {
    m_currentOperation = nullptr;

    runNextOperation();
}

void IDFServiceProcessingPipeline::runNextOperation() {
    // Определяем следующую последовательность операций.
    if (m_currentOperation == nullptr) {
        OperationSequence nextSequence(m_currentOperation, m_inputPathsPreparatorOperation);
        if (!m_operationsTransitions.containSequence(nextSequence)) {
            qDebug() << __PRETTY_FUNCTION__ << "->BAD_SEQUENCE";
            emit pipelineFinished(IDFServiceOutputData());

            return;
        } else {
            m_operationsTransitions.runTransition(nextSequence);
        }
    } else {
        OperationSequence nextSequence(m_currentOperation, m_currentOperation->getNextOperation());
        if (!m_operationsTransitions.containSequence(nextSequence)) {
            qDebug() << __PRETTY_FUNCTION__ << "->BAD_SEQUENCE";

            disconnect(m_currentOperation, nullptr, nullptr, nullptr);
            disconnect(this, nullptr, m_currentOperation, nullptr);

            emit pipelineFinished(IDFServiceOutputData());

            return;
        } else {
            m_operationsTransitions.runTransition(nextSequence);
        }
    }

    // Запускаем операцию.
    if (m_currentOperation == nullptr) {
        return;
    } else {
        m_currentOperation->start();
    }
}

void IDFServiceProcessingPipeline::onOperationFinished() {
    if (m_pipelineInterrupted) {
        if (m_currentOperation != nullptr) {
            disconnect(m_currentOperation, nullptr, nullptr, nullptr);
            disconnect(this, nullptr, m_currentOperation, nullptr);
        }

        emit pipelineInterrupted();

        setStatus(IDLE);

        return;
    }

    runNextOperation();
}

void IDFServiceProcessingPipeline::setOperationsTransitions() {
    m_operationsTransitions.clear();


    OperationSequence inputPathsPreparatorSeq(nullptr, m_inputPathsPreparatorOperation);
    OperationTransition inputPathsPreparatorSeqTransition([this] () {
        m_inputPathsPreparatorOperation->setInputData(m_inputData);

        m_currentOperation = m_inputPathsPreparatorOperation;

        connect(m_currentOperation, SIGNAL(finished()), this, SLOT(onOperationFinished()));
        connect(m_currentOperation, SIGNAL(publishProgress(OperationProgress)), this, SIGNAL(publishProgress(OperationProgress)));

        // ===
        qDebug() << "IDFServiceProcessingPipeline::setOperationsTransitions() -> PREPARE_INPUT_PATHS";
        // ===
    });

    m_operationsTransitions.setTransition(inputPathsPreparatorSeq, inputPathsPreparatorSeqTransition);


    OperationSequence imagesPathsFinderSeq(m_inputPathsPreparatorOperation, m_imagesPathsFinderOperation);
    OperationTransition imagesPathsFinderSeqTransition([this] () {
        disconnect(m_currentOperation, nullptr, nullptr, nullptr);
        disconnect(this, nullptr, m_currentOperation, nullptr);

        m_inputPaths = m_inputPathsPreparatorOperation->getPaths();
        std::shared_ptr<Paths> inputPathsPtr(new Paths(m_inputPaths));
        m_imagesPathsFinderOperation->setPaths(inputPathsPtr);

        m_currentOperation = m_imagesPathsFinderOperation;

        connect(m_currentOperation, SIGNAL(finished()), this, SLOT(onOperationFinished()));
        connect(m_currentOperation, SIGNAL(publishProgress(OperationProgress)), this, SIGNAL(publishProgress(OperationProgress)));

        // ===
        qDebug() << "IDFServiceProcessingPipeline::setOperationsTransitions() -> FINDING_IMAGES_PATHS";
        // ===
    });

    m_operationsTransitions.setTransition(imagesPathsFinderSeq, imagesPathsFinderSeqTransition);


    OperationSequence histogramBuilderSeq(m_imagesPathsFinderOperation, m_histogramsBuilderOperation);
    OperationTransition histogramBuilderSeqTransition([this] () {
        disconnect(m_currentOperation, nullptr, nullptr, nullptr);
        disconnect(this, nullptr, m_currentOperation, nullptr);

        std::shared_ptr<ImagesPaths> imagesPathsPtr = m_imagesPathsFinderOperation->getImagesPaths();
        m_histogramsBuilderOperation->setImagesPaths(imagesPathsPtr);

        m_currentOperation = m_histogramsBuilderOperation;

        connect(m_currentOperation, SIGNAL(finished()), this, SLOT(onOperationFinished()));
        connect(m_currentOperation, SIGNAL(publishProgress(OperationProgress)), this, SIGNAL(publishProgress(OperationProgress)));

        // ===
        qDebug() << "IDFServiceProcessingPipeline::setOperationsTransitions() -> BUILDING_HISTOGRAMS";
        // ===
    });

    m_operationsTransitions.setTransition(histogramBuilderSeq, histogramBuilderSeqTransition);


    OperationSequence histogramsComparatorSeq(m_histogramsBuilderOperation, m_histogramsComparatorOperation);
    OperationTransition histogramsComparatorSeqTransition([this] () {
        disconnect(m_currentOperation, nullptr, nullptr, nullptr);
        disconnect(this, nullptr, m_currentOperation, nullptr);

        std::shared_ptr<ImagesHistograms> histograms = m_histogramsBuilderOperation->getImagesHistograms();
        m_histogramsComparatorOperation->setImagesHistograms(histograms);

        m_currentOperation = m_histogramsComparatorOperation;

        connect(m_currentOperation, SIGNAL(finished()), this, SLOT(onOperationFinished()));
        connect(m_currentOperation, SIGNAL(publishProgress(OperationProgress)), this, SIGNAL(publishProgress(OperationProgress)));

        // ===
        qDebug() << "IDFServiceProcessingPipeline::setOperationsTransitions() -> COMPARE_HISTOGRAMS";
        // ===
    });

    m_operationsTransitions.setTransition(histogramsComparatorSeq, histogramsComparatorSeqTransition);


    OperationSequence finishSeq(m_histogramsComparatorOperation, nullptr);
    OperationTransition finishSeqTransition([this] () {
        disconnect(m_currentOperation, nullptr, nullptr, nullptr);
        disconnect(this, nullptr, m_currentOperation, nullptr);

        std::shared_ptr<ImagesDuplicatesGroups> imagesDuplicatesGroups = m_histogramsComparatorOperation->getImagesDuplicates();

        m_outpuData.setDuplicatesGroups(imagesDuplicatesGroups);;

        m_currentOperation = nullptr;

        emit pipelineFinished(m_outpuData);

        setStatus(IDLE);
    });

    m_operationsTransitions.setTransition(finishSeq, finishSeqTransition);
}
