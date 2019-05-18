#include "ImageDuplicatesFinderModule.h"
#include "DuplicateImagesListModelManager.h"

#include "InputFoldersModel.h"



void ImageDuplicatesFinderModule::init(QQmlContext* ctxt) {
    auto duplicateImagesListModelManager = new DuplicateImagesListModelManager();

    ctxt->setContextProperty("DuplicateImagesListModelsManager", duplicateImagesListModelManager);


    auto inputFoldersModel = new InputFoldersModel();

    ctxt->setContextProperty("InputFoldersModel", inputFoldersModel);
}
