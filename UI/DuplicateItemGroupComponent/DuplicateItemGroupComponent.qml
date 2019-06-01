import QtQuick 2.0
import Style 1.0
import "../UIKit"



Item {
    id: duplicateItemGroupComponent

    signal toolbarLeftButtonClicked()

    TopToolBar {
        id: topToolBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        toolBarText: "Дубликаты изображения"

        leftButtonVisible: true
        rightButtonVisible: false

        onLeftButtonClicked: {
            toolbarLeftButtonClicked()
        }
    }
}
