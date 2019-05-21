import QtQuick 2.0
import QtQuick.Controls 2.5
import "InputFoldersComponent"
import "DuplicateItemsListComponent"



StackView {
    id: coordinator


    property Component inputFoldersComponent: InputFoldersComponent {
        onToolbarRightButtonClicked: {
            coordinator.push(duplicateItemsListComponent, StackView.Immediate)
        }

        onRemoveFolderButtonClicked: {

        }

        onStartButtonClicked: {
            coordinator.push(duplicateItemsListComponent, StackView.Immediate)
        }
    }

    property Component duplicateItemsListComponent: DuplicateItemsListComponent {
        onToolbarLeftButtonClicked: {
            coordinator.pop(StackView.Immediate)
        }
    }


    initialItem: inputFoldersComponent
}
