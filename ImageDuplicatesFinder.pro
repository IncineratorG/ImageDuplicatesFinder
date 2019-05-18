QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    Services/ImageDuplicatesFinderService/IDFService.cpp \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.cpp \
    Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.cpp \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputDataItem.cpp \
    Services/ImageDuplicatesFinderService/Data/Path.cpp \
    Services/ImageDuplicatesFinderService/Data/Paths.cpp \
    Services/ImageDuplicatesFinderService/Data/ImageDuplicatesGroup.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagesDuplicatesGroups.cpp \
    Services/ImageDuplicatesFinderService/Data/ImageHistogram.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagePath.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagesPaths.cpp \
    Services/ImageDuplicatesFinderService/Data/ImagesHistograms.cpp \
    Services/ImageDuplicatesFinderService/Pipeline/IDFServiceProcessingPipeline.cpp \
    Services/ImageDuplicatesFinderService/Pipeline/AbstractOperation.cpp \
    Services/ImageDuplicatesFinderService/Pipeline/OperationSequence.cpp \
    Services/ImageDuplicatesFinderService/Pipeline/OperationTransition.cpp \
    Services/ImageDuplicatesFinderService/Pipeline/PipelineOperationsTransitions.cpp \
    Services/ImageDuplicatesFinderService/HistogramsComparator/AbstractHistogramsComparator.cpp \
    Services/ImageDuplicatesFinderService/HistogramsComparator/SequentialHistogramsComparator.cpp \
    Services/ImageDuplicatesFinderService/ImagesHistogramsBuilder/AbstractImagesHistogramsBuilder.cpp \
    Services/ImageDuplicatesFinderService/ImagesHistogramsBuilder/SequentialImagesHistogramsBuilder.cpp \
    Services/ImageDuplicatesFinderService/ImagesPathsFinder/AbstractImagesPathsFinder.cpp \
    Services/ImageDuplicatesFinderService/ImagesPathsFinder/SequentialImagesPathsFinder.cpp \
    Modules/ImageDuplicatesFinder/ImageDuplicatesFinderModule.cpp \
    Modules/ImageDuplicatesFinder/DuplicateImagesListModel.cpp \
    Modules/ImageDuplicatesFinder/DuplicateImagesListModelManager.cpp \
    Modules/ImageDuplicatesFinder/InputFoldersModel.cpp \
    Modules/ImageDuplicatesFinder/InputFoldersModelManager.cpp \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceController.cpp \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceDataWarehouse.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Services/ImageDuplicatesFinderService/IDFService.h \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputData.h \
    Services/ImageDuplicatesFinderService/Data/IDFServiceOutputData.h \
    Services/ImageDuplicatesFinderService/Data/IDFServiceInputDataItem.h \
    Services/ImageDuplicatesFinderService/Data/Path.h \
    Services/ImageDuplicatesFinderService/Data/Paths.h \
    Services/ImageDuplicatesFinderService/Data/ImageDuplicatesGroup.h \
    Services/ImageDuplicatesFinderService/Data/ImagesDuplicatesGroups.h \
    Services/ImageDuplicatesFinderService/Data/ImageHistogram.h \
    Services/ImageDuplicatesFinderService/Data/ImagePath.h \
    Services/ImageDuplicatesFinderService/Data/ImagesPaths.h \
    Services/ImageDuplicatesFinderService/Data/ImagesHistograms.h \
    Services/ImageDuplicatesFinderService/Pipeline/IDFServiceProcessingPipeline.h \
    Services/ImageDuplicatesFinderService/Pipeline/AbstractOperation.h \
    Services/ImageDuplicatesFinderService/Pipeline/OperationSequence.h \
    Services/ImageDuplicatesFinderService/Pipeline/OperationTransition.h \
    Services/ImageDuplicatesFinderService/Pipeline/PipelineOperationsTransitions.h \
    Services/ImageDuplicatesFinderService/HistogramsComparator/AbstractHistogramsComparator.h \
    Services/ImageDuplicatesFinderService/HistogramsComparator/SequentialHistogramsComparator.h \
    Services/ImageDuplicatesFinderService/ImagesHistogramsBuilder/AbstractImagesHistogramsBuilder.h \
    Services/ImageDuplicatesFinderService/ImagesHistogramsBuilder/SequentialImagesHistogramsBuilder.h \
    Services/ImageDuplicatesFinderService/ImagesPathsFinder/AbstractImagesPathsFinder.h \
    Services/ImageDuplicatesFinderService/ImagesPathsFinder/SequentialImagesPathsFinder.h \
    Modules/ImageDuplicatesFinder/ImageDuplicatesFinderModule.h \
    Modules/ImageDuplicatesFinder/DuplicateImagesListModel.h \
    Modules/ImageDuplicatesFinder/DuplicateImagesListModelManager.h \
    Modules/ImageDuplicatesFinder/InputFoldersModel.h \
    Modules/ImageDuplicatesFinder/InputFoldersModelManager.h \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceController.h \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceDataWarehouse.h
