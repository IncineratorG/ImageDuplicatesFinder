import QtQuick 2.0
import "../UIKit"



Item {
    id: duplicateItemsGroupsComponent

    TopToolBar {
        id: topToolBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        toolBarText: "Список дубликатов изображений"

        leftButtonVisible: false
        rightButtonVisible: false
    }
}
