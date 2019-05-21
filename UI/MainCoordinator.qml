import QtQuick 2.0
import QtQuick.Controls 2.5
import "InputFoldersComponent"
import "DuplicateItemsListComponent"



StackView {
    id: coordinator


    property Component inputFoldersComponent: InputFoldersComponent {
        onRemoveFolderButtonClicked: {

        }

        onStartButtonClicked: {
            console.log("ON_START_BUTTON_CLICKED")

            coordinator.push(duplicateItemsListComponent, StackView.Immediate)
        }
    }

    property Component duplicateItemsListComponent: DuplicateItemsListComponent {

    }


    initialItem: inputFoldersComponent
}
