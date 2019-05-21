#include "ImageDuplicatesFinderModule.h"
#include "InputFoldersComponent/InputFoldersModel.h"
#include "InputFoldersComponent/InputFoldersModelManager.h"
#include "DuplicateItemsListComponent/DuplicateItemsListModel.h"
#include "DuplicateItemsListComponent/DuplicateItemsListModelManager.h"



void ImageDuplicatesFinderModule::init(QQmlContext* ctxt) {
    auto inputFoldersModel = new InputFoldersModel();
    ctxt->setContextProperty("InputFoldersModel", inputFoldersModel);

    auto duplicatesListModel = new DuplicateItemsListModel();
    ctxt->setContextProperty("DuplicatesListModel", duplicatesListModel);


    auto inputFoldersModelManager = new InputFoldersModelManager(inputFoldersModel);
    ctxt->setContextProperty("InputFoldersModelManager", inputFoldersModelManager);

    auto duplicatesListModelManager = new DuplicateItemsListModelManager(duplicatesListModel);
    ctxt->setContextProperty("DuplicatesListModelManager", duplicatesListModelManager);
}
