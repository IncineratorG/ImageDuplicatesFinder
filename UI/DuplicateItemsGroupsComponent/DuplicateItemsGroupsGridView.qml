import QtQuick 2.0
import Style 1.0
import "../UIKit"




Rectangle {
    id: gridViewWrapper

    color: "#F4F8FA"

    GridView {
        id: gridView

        anchors.fill: parent

        anchors.bottomMargin: 4

        cellHeight: 150
        cellWidth: 150

        clip: true

        delegate: Rectangle {
            id: gvDelegate

            height: gridView.cellHeight
            width: gridView.cellWidth

            color: "transparent"

            Rectangle {
                id: innerRect

                anchors.fill: parent

                anchors.margins: 4

                color: "transparent"

                border.width: 1
                border.color: "grey"

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
