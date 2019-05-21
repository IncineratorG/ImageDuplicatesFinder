import QtQuick 2.0
import QtQuick.Dialogs 1.3
import Style 1.0
import "../UIKit"



Item {
    id: inputFoldersComponent

    signal addFolderButtonClicked()
    signal removeFolderButtonClicked(var index)
    signal startButtonClicked()

    TopToolBar {
        id: topToolBarWrapper

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    InputFoldersListView {
        id: inputFoldersListView

        anchors.top: topToolBarWrapper.bottom
        anchors.bottom: bottomButtonsWrapper.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 4

        onAddFolderButtonClicked: {
            fileDialog.open()

            inputFoldersComponent.addFolderButtonClicked()
        }

        onRemoveFolderButtonClicked: {
            inputFoldersComponent.removeFolderButtonClicked(index)
        }
    }

    Item {
        id: bottomButtonsWrapper

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.bottomMargin: 4

        height: Style.elementHeight

        UIButton {
            id: startButton

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            width: 100

            textColorDefault: "white"
            textColorPressed: "white"

            borderColorDefault: "#26A9F7"
            borderColorPressed: "#4FC3F7"

            backgroundColorDefault: "#26A9F7"
            backgroundColorPressed: "#4FC3F7"

            text: "Start"

            onClicked: {
                inputFoldersComponent.startButtonClicked()
            }
        }
    }

    FileDialog {
        id: fileDialog

        visible: false

        selectFolder: true

        title: "Please choose a folder"

        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
        }
    }
}
