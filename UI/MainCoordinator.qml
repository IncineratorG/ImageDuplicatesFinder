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
//                console.log("CLICK")

//                if (loader.visible) {
//                    loader.sourceComponent = undefined
//                    loader.z = -1
//                    loader.visible = false
//                } else {
//                    loader.sourceComponent = rect
//                    loader.z = 50
//                    loader.visible = true
//                }


                coordinatorStack.pop(StackView.Immediate)
            }

            onNotDuplicateButtonClicked: {
//                loader.sourceComponent = coordinatorStack.notDuplicateBlockingComponent
//                loader.visible = true
//                loader.z = 50
            }

            onRemoveItemButtonClicked: {
//                loader.sourceComponent = coordinatorStack.removeDuplicateImageBlockingComponent
//                loader.visible = true
//                loader.z = 50
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

        property Component notDuplicateBlockingComponent: BlockingComponent {
            okButtonText: "Не дубликат"
            cancelButtonText: "Отмена"

            onOkButtonClicked: {
                console.log("NOT_DUPLICATE_CLICKED")

                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }

            onCancelButtonClicked: {
                console.log("CANCEL")

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

        property Component removeDuplicateImageBlockingComponent: BlockingComponent {
            okButtonText: "Удалить"
            cancelButtonText: "Отмена"

            onOkButtonClicked: {
                console.log("REMOVE_CLICKED")

                loader.sourceComponent = undefined
                loader.visible = false
                loader.z = -1
            }

            onCancelButtonClicked: {
                console.log("CANCEL")

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



//    WaitComponent {
//        id: waitComponent

//        anchors.fill: parent

//        visible: IDFServiceController.serviceStatus != "idle"
//        z: IDFServiceController.serviceStatus == "idle" ? -1 : 10

//        progressText: IDFServiceController.currentServiceOperationName
//        progressValue: IDFServiceController.currentServiceOperationProgress

//        onCancelButtonClicked: {
//            InputFoldersModelManager.stopProcessing()
//        }
//    }
