import QtQuick 2.0
import QtQuick.Controls 2.5
import "InputFoldersComponent"
import "DuplicateItemsGroupsComponent"



StackView {
    id: coordinator


    property Component inputFoldersComponent: InputFoldersComponent {
        onToolbarRightButtonClicked: {
            coordinator.push(duplicateItemsGroupsComponent, StackView.Immediate)
        }

        onRemoveFolderButtonClicked: {

        }

        onStartButtonClicked: {
            coordinator.push(duplicateItemsGroupsComponent, StackView.Immediate)
        }
    }

    property Component duplicateItemsGroupsComponent: DuplicateItemsGroupsComponent {
        onToolbarLeftButtonClicked: {
            coordinator.pop(StackView.Immediate)
        }
    }


    initialItem: inputFoldersComponent
}
