import QtQuick 2.0
import Style 1.0
import "Assets"
import "UIKit"



Rectangle {
    id: blockingComponent

    property string okButtonText: "Ok"
    property string cancelButtonText: "Cancel"

    signal okButtonClicked()
    signal cancelButtonClicked()
    signal outOfAreaClicked()

    color: "#cc000000"

    MouseArea {
        anchors.fill: parent

        onClicked: {
            outOfAreaClicked()
        }
    }

    Rectangle {
        anchors.centerIn: parent

        height: 150
        width: 300

        color: "#66000000"

        radius: 4

        MouseArea {
            anchors.fill: parent

            onClicked: {

            }
        }

        Rectangle {
            id: buttonsWrapper

            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            anchors.margins: 4

            height: Style.elementHeightWithMargins

            color: "transparent"

            Rectangle {
                id: okButtonWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                width: parent.width / 2 - 2

                color: "transparent"

                UIButton {
                    id: okButton

                    anchors.fill: parent

                    textColorDefault: "white"
                    textColorPressed: "white"

                    borderColorDefault: "#D50000"
                    borderColorPressed: "#8cD50000"

                    backgroundColorDefault: "#D50000"
                    backgroundColorPressed: "#E53935"

                    text: okButtonText

                    onClicked: {
                        blockingComponent.okButtonClicked()
                    }
                }
            }

            Rectangle {
                id: cancelButtonWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: okButtonWrapper.right
                anchors.right: parent.right

                anchors.leftMargin: 4

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

                    text: cancelButtonText

                    onClicked: {
                        blockingComponent.cancelButtonClicked()
                    }
                }
            }
        }
    }
}

//Item {
//    MouseArea {
//        anchors.fill: parent

//        propagateComposedEvents: false

//        onClicked: console.log("CLICKED")
//    }

//    Rectangle {
//        anchors.fill: parent

//        color: "#cc000000"
//    }

////    Component.onCompleted: console.log("BLOCKING_COMPONENT->ON_COMPLETED")
//}
