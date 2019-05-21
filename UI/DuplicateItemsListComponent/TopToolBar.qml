import QtQuick 2.0
import Style 1.0



Rectangle {
    id: topToolBarWrapper

    height: Style.elementHeight

    color: "transparent"

    Rectangle {
        id: bottomBorderLine

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 1

        color: "black"
    }
}
