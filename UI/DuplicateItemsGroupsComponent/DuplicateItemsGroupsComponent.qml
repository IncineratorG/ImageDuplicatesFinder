import QtQuick 2.0
import Style 1.0
import "../UIKit"



Item {
    id: duplicateItemsGroupsComponent

    signal toolbarLeftButtonClicked()
    signal duplicateItemGroupDoubleClicked(var groupId)

    MouseArea {
        anchors.fill: parent

        acceptedButtons: Qt.AllButtons

        onClicked: {
            if (mouse.button == Qt.BackButton) {
                toolbarLeftButtonClicked()
            } else if (mouse.button == Qt.ForwardButton) {
//                console.log("Forward button")
            }
        }
    }

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

            onDuplicateGroupDoubleClicked: {
                duplicateItemsGroupsComponent.duplicateItemGroupDoubleClicked(groupId)
            }
        }
    }
}
