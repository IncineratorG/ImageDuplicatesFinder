import QtQuick 2.0
import QtQuick.Dialogs 1.3
import Style 1.0
import "../UIKit"



Item {
    id: inputFoldersComponent

    signal addFolderButtonClicked()
    signal removeFolderButtonClicked(var index)
    signal startButtonClicked()
    signal toolbarRightButtonClicked()

    TopToolBar {
        id: topToolBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        visible: inputFoldersListView.visible

        toolBarText: "Выбор папок с изображениями"

        leftButtonVisible: false
        rightButtonVisible: DuplicatesGroupsModel.size > 0

        onRightButtonClicked: {
            inputFoldersComponent.toolbarRightButtonClicked()
        }
    }

    Item {
        id: inputFoldersListViewComponentWrapper

        anchors.top: topToolBar.bottom
        anchors.bottom: bottomButtonsWrapper.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 4

        InputFoldersListView {
            id: inputFoldersListView

            anchors.fill: parent

            visible: InputFoldersModel.size > 0

            onAddFolderButtonClicked: {
                fileDialog.open()

                inputFoldersComponent.addFolderButtonClicked()
            }

            onRemoveFolderButtonClicked: {
                InputFoldersModelManager.removeFolder(index)

                inputFoldersComponent.removeFolderButtonClicked(index)
            }
        }

        EmptyListViewComponent {
            id: emptyFoldersListViewComponent

            anchors.fill: parent

            visible: InputFoldersModel.size <= 0

            onAddFolderButtonClicked: {
                fileDialog.open()

                inputFoldersComponent.addFolderButtonClicked()
            }
        }
    }

    Item {
        id: bottomButtonsWrapper

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.bottomMargin: InputFoldersModel.size > 0 ? 4 : 0

        height: InputFoldersModel.size > 0 ? Style.elementHeightWithMargins : 0

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

            text: "Начать"

            onClicked: {
                DuplicatesGroupsModelManager.clearModel()

                InputFoldersModelManager.startProcessing()

                inputFoldersComponent.startButtonClicked()
            }
        }
    }

    FileDialog {
        id: fileDialog

        visible: false

        selectFolder: true

        title: "Выберите папку"

        onAccepted: {
            InputFoldersModelManager.addFolder(fileDialog.fileUrls)
        }
    }
}
