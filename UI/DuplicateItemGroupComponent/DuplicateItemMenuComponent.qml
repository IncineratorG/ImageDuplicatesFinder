import QtQuick 2.0
import QtGraphicalEffects 1.0
import Style 1.0
import "../Assets"
import "../UIKit"



Item {
    id: menuComponent

    visible: false
    z: visible ? 10 : -1

    width: 110
    height: 80

    signal openButtonClicked()
    signal notDuplicateButtonClicked()
    signal removeButtonClicked()

    function show(x, y) {
        menuComponent.x = x
        menuComponent.y = y
        menuComponent.visible = true
    }

    function hide() {
        menuComponent.visible = false
    }

//    DropShadow {
//        anchors.fill: parent

//        anchors.margins: 4

//        horizontalOffset: 8
//        verticalOffset: 8
////        radius: 8.0
////        samples: 17
////        color: "#80000000"
//        color: "grey"
////        source: butterfly
//    }

//    MouseArea {
//        anchors.fill: parent

//        propagateComposedEvents: true

//        onClicked: {
//            console.log("ON_MENU_CLICKED")
//        }
//    }

    Rectangle {
        anchors.fill: parent

        color: "#FAFAFA"

        radius: 4

        Rectangle {
            id: openButtonWrapper

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            height: Style.elementHeight

            color: "transparent"

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true

                onEntered: {
                    openButtonWrapper.color = "#F4F8FA"
                }

                onExited: {
                    openButtonWrapper.color = "transparent"
                }

                onClicked: {
                    menuComponent.openButtonClicked()
                }
            }

            Rectangle {
                id: openButtonImageWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                width: openButtonImageWrapper.height

                color: "transparent"

                Image {
                    id: openButtonImage

                    anchors.fill: parent

                    anchors.margins: 4

                    source: "../Assets/open_image_folder.png"
                }
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

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true

                onEntered: {
                    notDuplicateButtonWrapper.color = "#F4F8FA"
                }

                onExited: {
                    notDuplicateButtonWrapper.color = "transparent"
                }

                onClicked: {
                    menuComponent.notDuplicateButtonClicked()
                }
            }

            Rectangle {
                id: notDuplicateImageWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                width: notDuplicateImageWrapper.height

                color: "transparent"

                Image {
                    id: notDuplicateImage

                    anchors.fill: parent

                    anchors.margins: 4

                    source: "../Assets/stop.png"
                }
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

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true

                onEntered: {
                    deleteButtonWrapper.color = "#F4F8FA"
                }

                onExited: {
                    deleteButtonWrapper.color = "transparent"
                }

                onClicked: {
                    menuComponent.removeButtonClicked()
                }
            }

            Rectangle {
                id: deleteButtonImageWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                width: deleteButtonImageWrapper.height

                color: "transparent"

                Image {
                    id: deleteImage

                    anchors.fill: parent

                    anchors.margins: 4

                    source: "../Assets/trash.png"
                }
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
