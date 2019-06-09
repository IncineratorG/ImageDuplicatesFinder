import QtQuick 2.0
import Style 1.0
import "../Assets"
import "../UIKit"



Item {
    id: menuComponent

    visible: false
    z: visible ? 10 : -1

    width: 100
    height: 80

    function show(x, y) {
        menuComponent.x = x
        menuComponent.y = y
        menuComponent.visible = true
    }

    function hide() {
        menuComponent.visible = false
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            console.log("ON_MENU_CLICKED")
        }
    }

    Rectangle {
        anchors.fill: parent

        color: "white"

        Rectangle {
            id: openButtonWrapper

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            height: Style.elementHeight

            color: "transparent"

            Rectangle {
                id: openButtonImageWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                width: openButtonImageWrapper.height

                color: "grey"
            }

            Rectangle {
                id: openButtonTextWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: openButtonImageWrapper.right
                anchors.right: parent.right

                color: "transparent"

                Text {
                    id: openButtonText

                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter

                    anchors.leftMargin: 4

                    width: parent.width - 4

                    text: "Открыть"
                    font.pointSize: Style.elementTextSize - 1

                    color: "grey"
                }
            }
        }

        Rectangle {
            id: notDuplicateButtonWrapper

            anchors.top: openButtonWrapper.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            height: Style.elementHeight

            color: "transparent"

            Rectangle {
                id: notDuplicateImageWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                width: notDuplicateImageWrapper.height

                color: "grey"
            }

            Rectangle {
                id: notDuplicateTextWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: notDuplicateImageWrapper.right
                anchors.right: parent.right

                color: "transparent"

                Text {
                    id: notDuplicateButtonText

                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter

                    anchors.leftMargin: 4

                    width: parent.width - 4

                    text: "Не дубликат"
                    font.pointSize: Style.elementTextSize - 1

                    color: "grey"
                }
            }
        }

        Rectangle {
            id: deleteButtonWrapper

            anchors.top: notDuplicateButtonWrapper.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            height: Style.elementHeight

            color: "transparent"

            Rectangle {
                id: deleteButtonImageWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                width: deleteButtonImageWrapper.height

                color: "grey"
            }

            Rectangle {
                id: deleteButtonTextWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: deleteButtonImageWrapper.right
                anchors.right: parent.right

                color: "transparent"

                Text {
                    id: deleteButtonText

                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter

                    anchors.leftMargin: 4

                    width: parent.width - 4

                    text: "Удалить"
                    font.pointSize: Style.elementTextSize - 1

                    color: "grey"
                }
            }
        }
    }
}
