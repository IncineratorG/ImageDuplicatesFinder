import QtQuick 2.0
import QtQuick.Controls 2.5
import "InputFoldersComponent"
import "DuplicateItemsGroupsComponent"
import "DuplicateItemGroupComponent"



Item {
    id: coordinatorWrapper

    WaitComponent {
        id: waitComponent

        anchors.fill: parent

        visible: IDFServiceController.serviceStatus != "idle"

        progressText: IDFServiceController.currentServiceOperationName
        progressValue: IDFServiceController.currentServiceOperationProgress

        onCancelButtonClicked: {
            InputFoldersModelManager.stopProcessing()
        }
    }

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
                coordinatorStack.pop(StackView.Immediate)
            }
        }


        initialItem: inputFoldersComponent
    }
}
