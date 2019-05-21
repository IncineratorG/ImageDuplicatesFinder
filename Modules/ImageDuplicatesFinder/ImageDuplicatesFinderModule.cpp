#include "ImageDuplicatesFinderModule.h"
#include "DuplicateImagesListModelManager.h"

#include "InputFoldersComponent/InputFoldersModel.h"
#include "InputFoldersComponent/InputFoldersModelManager.h"



void ImageDuplicatesFinderModule::init(QQmlContext* ctxt) {
    auto inputFoldersModel = new InputFoldersModel();
    ctxt->setContextProperty("InputFoldersModel", inputFoldersModel);


    auto inputFoldersModelManager = new InputFoldersModelManager(inputFoldersModel);
    ctxt->setContextProperty("InputFoldersModelManager", inputFoldersModelManager);

    auto duplicateImagesListModelManager = new DuplicateImagesListModelManager();
    ctxt->setContextProperty("DuplicateImagesListModelsManager", duplicateImagesListModelManager);
}
