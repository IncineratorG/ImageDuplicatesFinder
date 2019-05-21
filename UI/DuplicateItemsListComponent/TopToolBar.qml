import QtQuick 2.0
import Style 1.0



Rectangle {
    id: topToolBarWrapper

    property string toolBarText: ""
    property bool leftButtonVisible: true
    property bool rightButtonVisible: true

    signal leftButtonClicked()
    signal rightButtonClicked()

    height: visible ? Style.elementHeight : 0

    color: "transparent"

    Rectangle {
        id: leftButtonWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        width: 30

        color: "transparent"

        visible: leftButtonVisible

        MouseArea {
            anchors.fill: parent

            onPressed: {
                leftButtonWrapper.color = "#F4F8FA"
            }

            onReleased: {
                leftButtonWrapper.color = "transparent"
            }

            onClicked: {
                leftButtonClicked()
            }
        }

        Image {
            anchors.fill: parent

            anchors.margins: 4

            source: "../Assets/left_arrow.png"
        }

        Rectangle {
            id: leftButtonWrapperRightSeparatorLine

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            width: 1

            color: "#F4F8FA"
        }
    }

    Rectangle {
        id: toolBarTextWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: leftButtonWrapper.right
        anchors.right: rightButtonWrapper.left

        color: "transparent"

        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width

            horizontalAlignment: Text.AlignHCenter

            text: toolBarText
            elide: Text.ElideRight
            font.pointSize: 12

            color: "black"
            opacity: 0.7
        }
    }

    Rectangle {
        id: rightButtonWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        width: 30

        color: "transparent"

        visible: rightButtonVisible

        MouseArea {
            anchors.fill: parent

            onPressed: {
                rightButtonWrapper.color = "#F4F8FA"
            }

            onReleased: {
                rightButtonWrapper.color = "transparent"
            }

            onClicked: {
                rightButtonClicked()
            }
        }

        Image {
            anchors.fill: parent

            anchors.margins: 4

            source: "../Assets/right_arrow.png"
        }

        Rectangle {
            id: rightButtonWrapperLeftSeparatorLine

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: 1

            color: "#F4F8FA"
        }
    }

    Rectangle {
        id: bottomBorderLine

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 1

        color: "#F4F8FA"
    }
}
