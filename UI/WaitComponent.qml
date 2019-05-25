import QtQuick 2.12
import Style 1.0
import "Assets"
import "UIKit"



Rectangle {
    id: waitComponent

    color: "#cc000000"

    z: 100

    Rectangle {
        anchors.centerIn: parent

        height: 150
        width: 300

        color: "#66000000"

        radius: 4

        Rectangle {
            id: contentWrapper

            anchors.top: parent.top
            anchors.bottom: cancelButtonWrapper.top
            anchors.left: parent.left
            anchors.right: parent.right

            color: "transparent"

            Rectangle {
                id: waitImageWrapper

                anchors.top: parent.top
                anchors.bottom: statusTextWrapper.top
                anchors.left: parent.left
                anchors.right: parent.right

                color: "transparent"

                Image {
                    id: waitImage

                    anchors.centerIn: parent

                    height: 32
                    width: 32

                    source: "Assets/wait.png"

                    RotationAnimation {
                        target: waitImage
                        from: 0;
                        to: 360;
                        duration: 2000
                        loops: Animation.Infinite
                        running: waitComponent.visible
                    }
                }
            }

            Rectangle {
                id: statusTextWrapper

                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right

                anchors.bottomMargin: 4

                height: Style.elementHeight

                color: "transparent"

                Text {
                    id: statusText

                    anchors.left: parent.left

                    width: parent.width
                    height: parent.height

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    text: "model.groupSize adjsfhaksdhfl;klkjasdf"
                    font.pointSize: Style.elementTextSize
                    color: "white"
                    elide: Text.ElideRight
                }
            }
        }

        Rectangle {
            id: cancelButtonWrapper

            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: Style.elementHeightWithMargins

            color: "transparent"

            UIButton {
                id: cancelButton

                anchors.fill: parent

                textColorDefault: "white"
                textColorPressed: "white"

                borderColorDefault: "#D50000"
                borderColorPressed: "#8cD50000"

                backgroundColorDefault: "#D50000"
                backgroundColorPressed: "#E53935"

                text: "Отмена"
            }
        }
    }
}
