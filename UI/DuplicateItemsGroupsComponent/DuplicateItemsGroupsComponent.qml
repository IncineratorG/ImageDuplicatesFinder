import QtQuick 2.0
import Style 1.0
import "../UIKit"



Item {
    id: duplicateItemsGroupsComponent

    signal toolbarLeftButtonClicked()

    TopToolBar {
        id: topToolBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        toolBarText: "Список дубликатов изображений"

        leftButtonVisible: true
        rightButtonVisible: false

        onLeftButtonClicked: {
            toolbarLeftButtonClicked()
        }
    }

    Rectangle {
        id: gridViewWrapper

        anchors.top: topToolBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        anchors.margins: 4

        color: "transparent"

        border.width: 1
        border.color: "black"

        DuplicateItemsGroupsGridView {
            anchors.fill: parent
        }
    }
}
