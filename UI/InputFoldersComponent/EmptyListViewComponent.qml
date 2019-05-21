import QtQuick 2.0
import Style 1.0
import "../UIKit"



Rectangle {
    id: emptyInputFoldersListViewComponent

    signal addFolderButtonClicked()

    color: "#F4F8FA"

    Item {
        id: addButtonWrapper

        height: Style.elementHeightWithMargins
        width: 120

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        UIButton {
            id: addFolderButton

            anchors.fill: parent

            textColorDefault: "white"
            textColorPressed: "white"

            borderColorDefault: "#26A9F7"
            borderColorPressed: "#4FC3F7"

            backgroundColorDefault: "#26A9F7"
            backgroundColorPressed: "#4FC3F7"

            text: "Добавить папку"

            onClicked: {
                addFolderButtonClicked()
            }
        }
    }
}
