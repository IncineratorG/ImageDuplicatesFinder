import QtQuick 2.0
import Style 1.0



Item {
    id: duplicateItemsListComponent

    signal toolbarLeftButtonClicked()

    TopToolBar {
        id: topToolBarWrapper

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        toolBarText: "Список дубликатов изображений"

        leftButtonVisible: InputFoldersModel.size > 0
        rightButtonVisible: false

        onLeftButtonClicked: {
            toolbarLeftButtonClicked()
        }
    }
}
