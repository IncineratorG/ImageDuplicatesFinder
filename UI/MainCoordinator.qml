import QtQuick 2.0
import QtQuick.Controls 2.5
import "InputFoldersComponent"



StackView {
    id: coordinator

    property Component inputFoldersComponent: InputFoldersComponent {
        onRemoveFolderButtonClicked: {

        }

        onStartButtonClicked: {
            console.log("ON_START_BUTTON_CLICKED")
        }
    }


    initialItem: inputFoldersComponent
}
