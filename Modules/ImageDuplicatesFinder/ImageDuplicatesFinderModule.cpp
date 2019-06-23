#include "ImageDuplicatesFinderModule.h"
#include "InputFoldersComponent/InputFoldersModel.h"
#include "InputFoldersComponent/InputFoldersModelManager.h"
#include "DuplicateItemsGroupsComponent/DuplicateItemsGroupsModel.h"
#include "DuplicateItemsGroupsComponent/DuplicateItemsGroupsModelManager.h"
#include "DuplicateItemGroupComponent/DuplicateItemGroupModel.h"
#include "DuplicateItemGroupComponent/DuplicateItemGroupModelManager.h"
#include "ServiceMediatorLayer/IDFServiceController.h"
#include "Modules/ImageDuplicatesFinder/Data/ResultViewTypesModel.h"



void ImageDuplicatesFinderModule::init(QQmlContext* ctxt) {
    ctxt->setContextProperty("IDFServiceController", IDFServiceController::getInstance());

    auto resultViewTypesModel = new ResultViewTypesModel();
    ctxt->setContextProperty("ResultViewTypesModel", resultViewTypesModel);


    auto inputFoldersModel = new InputFoldersModel();
    ctxt->setContextProperty("InputFoldersModel", inputFoldersModel);

    auto duplicatesGroupsModel = new DuplicateItemsGroupsModel();
    ctxt->setContextProperty("DuplicatesGroupsModel", duplicatesGroupsModel);

    auto duplicateGroupModel = new DuplicateItemGroupModel();
    ctxt->setContextProperty("DuplicateGroupModel", duplicateGroupModel);


    auto inputFoldersModelManager = new InputFoldersModelManager(inputFoldersModel);
    ctxt->setContextProperty("InputFoldersModelManager", inputFoldersModelManager);

    auto duplicatesGroupsModelManager = new DuplicateItemsGroupsModelManager(duplicatesGroupsModel);
    ctxt->setContextProperty("DuplicatesGroupsModelManager", duplicatesGroupsModelManager);

    auto duplicateGroupModelManager = new DuplicateItemGroupModelManager(duplicateGroupModel);
    ctxt->setContextProperty("DuplicateGroupModelManager", duplicateGroupModelManager);
}
