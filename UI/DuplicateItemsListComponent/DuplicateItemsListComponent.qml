import QtQuick 2.0
import Style 1.0



Item {
    id: duplicateItemsListComponent

    signal toolbarLeftButtonClicked()

    TopToolBar {
        id: topToolBar

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

    Item {
        id: duplicateItemsListViewComponentWrapper

        anchors.top: topToolBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 4

        DuplicateItemsListView {
            id: duplicateItemsListView

            anchors.fill: parent
        }
    }
}
