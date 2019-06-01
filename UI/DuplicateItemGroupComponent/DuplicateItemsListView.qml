import QtQuick 2.12
import QtQuick.Controls 1.4
import Style 1.0
import "../Assets"
import "../UIKit"



Rectangle {
    id: duplicateItemsListViewComponent

    signal duplicateItemDoubleClicked(var itemId)

    color: "#F4F8FA"

    Rectangle {
        id: generalDuplicateImageWrapper

        anchors.top: parent.top
        anchors.left: parent.left

        width: 250
        height: 250

        color: "transparent"

        Image {
            id: generalDuplicateImage

            anchors.fill: parent

            source: DuplicateGroupModel.generalImage

            sourceSize.width: parent.width
            sourceSize.height: parent.height

            asynchronous: true
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

            spacing: 4

            clip: true

            delegate: Rectangle {
                id: itemDelegate

                width: parent.width
                height: 40

                color: listView.currentIndex == model.index ? "#E9F4FA" : "white"

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        listView.currentIndex = model.index
                    }

                    onDoubleClicked: {
                        listView.currentIndex = model.index

                        duplicateItemDoubleClicked(model.itemId)

                        DuplicateGroupModelManager.openItemPath(model.itemId)
                    }
                }

                Rectangle {
                    id: imagePathWrapper

                    anchors.fill: parent

                    color: "transparent"

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
            }

            model: DuplicateGroupModel
        }
    }
}
