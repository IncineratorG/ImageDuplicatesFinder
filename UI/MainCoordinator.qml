import QtQuick 2.0
import QtQuick.Controls 2.5
import "InputFoldersComponent"
import "DuplicateItemsGroupsComponent"
import "DuplicateItemGroupComponent"



Item {
    id: coordinatorWrapper

    StackView {
        id: coordinatorStack

//        // ===
//        focus: true
//        Keys.onPressed: {
//            console.log("KEY_PRESSED")
//        }

//        Component.onCompleted: forceActiveFocus()
//        // ===

        anchors.fill: parent

        property Component inputFoldersComponent: InputFoldersComponent {
            onToolbarRightButtonClicked: {
                coordinatorStack.push(duplicateItemsGroupsComponent, StackView.Immediate)
            }

            onRemoveFolderButtonClicked: {

            }

            onStartButtonClicked: {
                coordinatorStack.push(duplicateItemsGroupsComponent, StackView.Immediate)
            }
        }

        property Component duplicateItemsGroupsComponent: DuplicateItemsGroupsComponent {
            onToolbarLeftButtonClicked: {
                coordinatorStack.pop(StackView.Immediate)
            }

            onDuplicateItemGroupDoubleClicked: {
                coordinatorStack.push(duplicateItemGroupComponent, StackView.Immediate)
            }
        }

        property Component duplicateItemGroupComponent: DuplicateItemGroupComponent {
            onToolbarLeftButtonClicked: {
                if (loader.visible) {
                    return
                } else {
                    coordinatorStack.pop(StackView.Immediate)
                }
            }

            onNotDuplicateButtonClicked: {
                coordinatorStack.notDuplicateComponentOkAction = function() {
                    DuplicateGroupModelManager.markItemAsNotDuplicate(itemId)
                }

                loader.sourceComponent = coordinatorStack.notDuplicateBlockingComponent
                loader.visible = true
                loader.z = 50

                loader.item.imagePath = DuplicateGroupModelManager.getItemImagePath(itemId)
                loader.item.imagePathString = DuplicateGroupModelManager.getItemImagePathText(itemId)
            }

            onRemoveItemButtonClicked: {
                coordinatorStack.removeDuplicateComponentOkAction = function() {
                    DuplicateGroupModelManager.removeItemFromDisk(itemId)
                }

                loader.sourceComponent = coordinatorStack.removeDuplicateImageBlockingComponent
                loader.visible = true
                loader.z = 50

                loader.item.imagePath = DuplicateGroupModelManager.getItemImagePath(itemId)
                loader.item.imagePathString = DuplicateGroupModelManager.getItemImagePathText(itemId)
            }
        }


        // ===
        Connections {
            target: IDFServiceController
            onServiceStatusChanged: {
                if (value != "idle") {
                    loader.sourceComponent = coordinatorStack.waitComponent
                    loader.visible = true
                    loader.z = 50
                } else {
                    loader.sourceComponent = undefined
                    loader.visible = false
                    loader.z = -1
                }
            }
        }

        Loader {
            id: loader

            anchors.fill: parent

            visible: false
        }

        property Component waitComponent: WaitComponent {
            progressText: IDFServiceController.currentServiceOperationName
            progressValue: IDFServiceController.currentServiceOperationProgress

            onCancelButtonClicked: {
                InputFoldersModelManager.stopProcessing()
            }
        }

        property var notDuplicateComponentOkAction: undefined
        property var notDuplicateComponentCancelAction: undefined
        property Component notDuplicateBlockingComponent: BlockingComponent {
            okButtonText: "Убрать"
            cancelButtonText: "Отмена"
            informationalTextValue: "Убрать из списка дубликатов?"

            onOkButtonClicked: {
                if (coordinatorStack.notDuplicateComponentOkAction != undefined) {
                    coordinatorStack.notDuplicateComponentOkAction()
                }
                coordinatorStack.notDuplicateComponentOkAction = undefined

                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }

            onCancelButtonClicked: {
                if (coordinatorStack.notDuplicateComponentCancelAction != undefined) {
                    coordinatorStack.notDuplicateComponentCancelAction()
                }
                coordinatorStack.notDuplicateComponentCancelAction = undefined

                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }

            onOutOfAreaClicked: {
                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }
        }

        property var removeDuplicateComponentOkAction: undefined
        property var removeDuplicateComponentCancelAction: undefined
        property Component removeDuplicateImageBlockingComponent: BlockingComponent {
            okButtonText: "Удалить"
            cancelButtonText: "Отмена"
            informationalTextValue: "Удалить изображение с диска?"

            onOkButtonClicked: {
                if (coordinatorStack.removeDuplicateComponentOkAction != undefined) {
                    coordinatorStack.removeDuplicateComponentOkAction()
                }
                coordinatorStack.removeDuplicateComponentOkAction = undefined

                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }

            onCancelButtonClicked: {
                if (coordinatorStack.removeDuplicateComponentCancelAction != undefined) {
                    coordinatorStack.removeDuplicateComponentCancelAction()
                }
                coordinatorStack.removeDuplicateComponentCancelAction = undefined

                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }

            onOutOfAreaClicked: {
                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }
        }
        // ===


        initialItem: inputFoldersComponent
    }
}
