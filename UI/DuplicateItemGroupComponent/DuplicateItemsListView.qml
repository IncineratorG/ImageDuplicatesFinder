import QtQuick 2.12
import QtQuick.Controls 1.4
import Style 1.0
import "../Assets"
import "../UIKit"



Rectangle {
    id: duplicateItemsListViewComponent

    signal duplicateItemDoubleClicked(var itemId)

    property var listViewItemHeight: 40
    property var listViewItemSpacing: 4

    color: "#F4F8FA"

//    MouseArea {
//        anchors.fill: parent

//        acceptedButtons: Qt.AllButtons

//        onClicked: {
//            if (mouse.button == Qt.BackButton) {
//                console.log("Back button");
//            } else if (mouse.button == Qt.ForwardButton) {
//                console.log("Forward button")
//            }
//        }
//    }


//    // ===
//    Rectangle {
//        id: listViewItemMenuComponent

//        width: 100
//        height: 100

//        color: "yellow"

//        visible: false

//        x: 490
//        y: 4
//        z: 10
//    }

//    function f(x, y, position) {
//        console.log("IN_FUNCTION: " + x + " - " + y + " - " + position)

//        var listViewItemHeight = 40
//        var listViewItemSpacing = 4

//        listViewItemMenuComponent.x = duplicateItemsListViewComponent.width - listViewItemMenuComponent.width
//        listViewItemMenuComponent.y = y + (listViewItemHeight + listViewItemSpacing) * (position + 1)
//        listViewItemMenuComponent.visible = true
//    }
//    // ===


    function toggleListViewItemMenu(itemXCoord, itemYCoord, itemPosition) {
        console.log(itemXCoord + " - " + itemYCoord + " - " + itemPosition)

        var menuComponentWidth = 100

        var itemMenuXPosition = duplicateItemsListViewComponent.width - menuComponentWidth
        var itemMenuYPosition = y + (listViewItemHeight + listViewItemSpacing) * (itemPosition + 1)

        console.log("MENU_X: " + itemMenuXPosition)
        console.log("MENU_Y: " + itemMenuYPosition)
        console.log()
    }


    Rectangle {
        id: generalDuplicateImageWrapper

        anchors.top: parent.top
        anchors.left: parent.left

        width: 250
        height: 250

        color: "transparent"

        Image {
            id: generalDuplicateImage

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            height: parent.height - Style.elementHeight

            source: DuplicateGroupModel.generalImage

            sourceSize.width: generalDuplicateImage.width
            sourceSize.height: generalDuplicateImage.height

            asynchronous: true
        }

        Rectangle {
            id: imagePathNameWrapper

            anchors.top: generalDuplicateImage.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            color: "transparent"

            Text {
                id: imagePathNameText

                anchors.left: parent.left

                anchors.verticalCenter: parent.verticalCenter

                anchors.leftMargin: 4

                width: parent.width - 6

                text: DuplicateGroupModel.generalImagePathText
                elide: Text.ElideMiddle
                font.pointSize: Style.elementTextSize - 1

                color: "grey"
            }
        }
    }

    Rectangle {
        id: listViewWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: generalDuplicateImageWrapper.right
        anchors.right: parent.right

        color: "transparent"

        ListView {
            id: listView

            anchors.fill: parent

            anchors.margins: 4

            spacing: listViewItemSpacing

            clip: true

            delegate: Rectangle {
                id: itemDelegate

                width: parent.width
                height: listViewItemHeight

                color: listView.currentIndex == model.index ? "#E9F4FA" : "white"

                Rectangle {
                    id: imagePathWrapper

                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: actionButtonsWrapper.left
//                    anchors.fill: parent

                    color: "transparent"

                    MouseArea {
                        anchors.fill: parent

                        propagateComposedEvents: true

                        onClicked: {
                            listView.currentIndex = model.index

                            DuplicateGroupModelManager.setGeneralImageItem(model.itemId)
                        }

                        onDoubleClicked: {
                            listView.currentIndex = model.index

                            duplicateItemDoubleClicked(model.itemId)

                            DuplicateGroupModelManager.openItemPath(model.itemId)
                        }
                    }

                    Text {
                        id: imagePathText

                        anchors.left: parent.left

                        anchors.verticalCenter: parent.verticalCenter

                        anchors.leftMargin: 4

                        width: parent.width - 6

                        text: model.imagePath
                        elide: Text.ElideMiddle
                        font.pointSize: Style.elementTextSize + 1

                        color: "black"
                    }
                }

                Rectangle {
                    id: actionButtonsWrapper

                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right

                    anchors.margins: 4

                    width: parent.height

                    color: "grey"

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            listView.currentIndex = model.index

                            duplicateItemsListViewComponent.toggleListViewItemMenu(actionButtonsWrapper.x, actionButtonsWrapper.y, listView.currentIndex)
                        }
                    }
                }
            }

            model: DuplicateGroupModel
        }
    }
}
