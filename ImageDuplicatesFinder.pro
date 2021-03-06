QT += quick
CONFIG += c++11

#RC_ICONS += app_icon.ico

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
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceController.cpp \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceDataWarehouse.cpp \
    Modules/ImageDuplicatesFinder/InputFoldersComponent/InputFoldersModel.cpp \
    Modules/ImageDuplicatesFinder/InputFoldersComponent/InputFoldersModelManager.cpp \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceDataConvertor.cpp \
    Modules/ImageDuplicatesFinder/Data/DuplicateItem.cpp \
    Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroup.cpp \
    Modules/ImageDuplicatesFinder/Data/InputFolderItem.cpp \
    Modules/ImageDuplicatesFinder/DuplicateItemsGroupsComponent/DuplicateItemsGroupsModel.cpp \
    Modules/ImageDuplicatesFinder/DuplicateItemsGroupsComponent/DuplicateItemsGroupsModelManager.cpp \
    Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroups.cpp \
    Services/ImageDuplicatesFinderService/InputPathsPreparator/AbstractInputPathsPreparator.cpp \
    Services/ImageDuplicatesFinderService/InputPathsPreparator/SequetialInputPathsPreparator.cpp \
    Services/ImageDuplicatesFinderService/Data/OperationProgress.cpp \
    Modules/ImageDuplicatesFinder/DuplicateItemGroupComponent/DuplicateItemGroupModel.cpp \
    Modules/ImageDuplicatesFinder/DuplicateItemGroupComponent/DuplicateItemGroupModelManager.cpp \
    Modules/ImageDuplicatesFinder/Data/IdGenerator.cpp \
    Modules/ImageDuplicatesFinder/Data/FolderInfoItem.cpp \
    Modules/ImageDuplicatesFinder/Data/FolderInfoItemsList.cpp \
    Modules/ImageDuplicatesFinder/Data/ResultViewTypesModel.cpp \
    Storages/Abstract/AbstractStorage.cpp \
    Storages/Abstract/AbstractAction.cpp \
    Storages/Abstract/AbstractStore.cpp \
    Storages/ImageDuplicatesFinder/IDFStorage.cpp \
    Storages/ImageDuplicatesFinder/IDFStore.cpp \
    Storages/ImageDuplicatesFinder/Actions/StartService.cpp \
    Storages/ImageDuplicatesFinder/Actions/StopService.cpp \
    Storages/StoragesManager.cpp \
    Services/ImageDuplicatesFinderService/Abstract/AbstractService.cpp \
    Services/ServicesManager.cpp

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
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceController.h \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceDataWarehouse.h \
    Modules/ImageDuplicatesFinder/InputFoldersComponent/InputFoldersModel.h \
    Modules/ImageDuplicatesFinder/InputFoldersComponent/InputFoldersModelManager.h \
    Modules/ImageDuplicatesFinder/ServiceMediatorLayer/IDFServiceDataConvertor.h \
    Modules/ImageDuplicatesFinder/Data/DuplicateItem.h \
    Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroup.h \
    Modules/ImageDuplicatesFinder/Data/InputFolderItem.h \
    Modules/ImageDuplicatesFinder/DuplicateItemsGroupsComponent/DuplicateItemsGroupsModel.h \
    Modules/ImageDuplicatesFinder/DuplicateItemsGroupsComponent/DuplicateItemsGroupsModelManager.h \
    Modules/ImageDuplicatesFinder/Data/DuplicateItemsGroups.h \
    Services/ImageDuplicatesFinderService/InputPathsPreparator/AbstractInputPathsPreparator.h \
    Services/ImageDuplicatesFinderService/InputPathsPreparator/SequetialInputPathsPreparator.h \
    Services/ImageDuplicatesFinderService/Data/OperationProgress.h \
    Modules/ImageDuplicatesFinder/DuplicateItemGroupComponent/DuplicateItemGroupModel.h \
    Modules/ImageDuplicatesFinder/DuplicateItemGroupComponent/DuplicateItemGroupModelManager.h \
    Modules/ImageDuplicatesFinder/Data/IdGenerator.h \
    Modules/ImageDuplicatesFinder/Data/FolderInfoItem.h \
    Modules/ImageDuplicatesFinder/Data/FolderInfoItemsList.h \
    Modules/ImageDuplicatesFinder/Data/ResultViewTypesModel.h \
    Storages/Abstract/AbstractStorage.h \
    Storages/Abstract/AbstractAction.h \
    Storages/Abstract/AbstractStore.h \
    Storages/ImageDuplicatesFinder/IDFStorage.h \
    Storages/ImageDuplicatesFinder/IDFStore.h \
    Storages/ImageDuplicatesFinder/Actions/StartService.h \
    Storages/ImageDuplicatesFinder/Actions/StopService.h \
    Storages/StoragesManager.h \
    Services/ImageDuplicatesFinderService/Abstract/AbstractService.h \
    Services/ServicesManager.h
