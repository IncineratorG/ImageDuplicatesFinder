#include "ImageDuplicatesFinderModule.h"
#include "InputFoldersComponent/InputFoldersModel.h"
#include "InputFoldersComponent/InputFoldersModelManager.h"
#include "DuplicateItemsGroupsComponent/DuplicateItemsGroupsModel.h"
#include "DuplicateItemsGroupsComponent/DuplicateItemsGroupsModelManager.h"



void ImageDuplicatesFinderModule::init(QQmlContext* ctxt) {
    auto inputFoldersModel = new InputFoldersModel();
    ctxt->setContextProperty("InputFoldersModel", inputFoldersModel);

    auto duplicatesGroupsModel = new DuplicateItemsGroupsModel();
    ctxt->setContextProperty("DuplicatesGroupsModel", duplicatesGroupsModel);


    auto inputFoldersModelManager = new InputFoldersModelManager(inputFoldersModel);
    ctxt->setContextProperty("InputFoldersModelManager", inputFoldersModelManager);

    auto duplicatesGroupsModelManager = new DuplicateItemsGroupsModelManager(duplicatesGroupsModel);
    ctxt->setContextProperty("DuplicatesGroupsModelManager", duplicatesGroupsModelManager);
}
