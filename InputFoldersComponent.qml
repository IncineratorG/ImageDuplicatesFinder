import QtQuick 2.11

import Style 1.0



Rectangle {
    id: inputFolders

    color: "transparent"

//    border.width: 1
//    border.color: "grey"

    InputFoldersTopPanel {
        id: topPanel

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.topMargin: 4
        anchors.leftMargin: 4
        anchors.rightMargin: 4

        height: Style.elementHeightWithMargins + 8
    }

    InputFoldersListView {
        id: listView

        anchors.top: topPanel.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 4

        anchors.topMargin: 10
    }
}
