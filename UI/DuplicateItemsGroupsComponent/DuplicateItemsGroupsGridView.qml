import QtQuick 2.0
import QtQuick.Controls 2.5
import Style 1.0
import "../UIKit"




Rectangle {
    id: gridViewWrapper

    signal duplicateGroupDoubleClicked(var groupId)

    color: "#F4F8FA"

    GridView {
        id: gridView

        anchors.fill: parent

        anchors.bottomMargin: 4

        cellHeight: 150
        cellWidth: 150

        clip: true

        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        highlightFollowsCurrentItem: true

        ScrollBar.vertical: ScrollBar {
            parent: gridView.parent

            anchors.top: gridView.top
            anchors.right: gridView.right
            anchors.bottom: gridView.bottom

            policy: ScrollBar.AsNeeded
        }

        delegate: Rectangle {
            id: gvDelegate

            height: gridView.cellHeight
            width: gridView.cellWidth

            color: "transparent"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    gridView.currentIndex = model.index
                }

                onDoubleClicked: {
                    duplicateGroupDoubleClicked(model.groupId)
                }
            }

            Rectangle {
                id: innerRect

                anchors.fill: parent

                anchors.margins: 4

                color: "transparent"

                border.width: 1
                border.color: "grey"

                radius: 2

                Rectangle {
                    id: imageWrapper

                    anchors.top: parent.top
                    anchors.bottom: textWrapper.top
                    anchors.left: parent.left
                    anchors.right: parent.right

                    color: "transparent"

                    Image {
                        id: duplicateImage

                        anchors.fill: parent

                        source: model.imagePath

                        sourceSize.width: duplicateImage.width
                        sourceSize.height: duplicateImage.height

                        asynchronous: true
                    }
                }

                Rectangle {
                    id: textWrapper

                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right

                    height: Style.elementHeight

                    color: "transparent"

                    Text {
                        id: duplicatesCountText

                        anchors.left: parent.left

                        width: parent.width
                        height: parent.height

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter

                        text: model.groupSize
                        font.pointSize: Style.elementTextSize + 1
                    }
                }
            }
        }

        model: DuplicatesGroupsModel
    }
}
