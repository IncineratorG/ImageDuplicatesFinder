import QtQuick 2.0
import "UIKit"



Rectangle {
    id: inputFoldersTopPanel

    color: "transparent"

//    border.width: 1
//    border.color: "grey"

    Rectangle {
        id: panelNameWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        width: parent.width * 0.3

        color: "transparent"

        Text {
            id: panelNameText

            anchors.left: parent.left

            anchors.leftMargin: 4

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width

            text: "Выбранные папки"
            elide: Text.ElideRight
            font.pointSize: 15

            color: "#448Aff"
        }
    }

    Rectangle {
        id: buttonsWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        anchors.topMargin: 4
        anchors.bottomMargin: 4
        anchors.rightMargin: 4

        width: parent.width * 0.4

//        color: "#2979ff"
        color: "transparent"

        UIButton {
            id: addFolderButton

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: parent.width < 150 ? parent.width : 150

            textColorDefault: "white"
            textColorPressed: "white"

            borderColorDefault: "#26A9F7"
            borderColorPressed: "#4FC3F7"

            backgroundColorDefault: "#26A9F7"
            backgroundColorPressed: "#4FC3F7"

            text: "Добавить папку"

            textPointSize: 11

            onClicked: console.log("BUTTON_CLICKED")
        }
    }
}
