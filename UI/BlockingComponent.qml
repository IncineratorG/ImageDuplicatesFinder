import QtQuick 2.0
import Style 1.0
import "Assets"
import "UIKit"



Rectangle {
    id: blockingComponent

    property string okButtonText: "Ok"
    property string cancelButtonText: "Cancel"
    property string imagePath: ""
    property string imagePathString: ""
    property string informationalTextValue: ""
    property var informationalTextAlignMode: Text.AlignRight

    signal okButtonClicked()
    signal cancelButtonClicked()
    signal outOfAreaClicked()

    color: "#cc000000"
//    color: "black"

    MouseArea {
        anchors.fill: parent

        onClicked: {
            outOfAreaClicked()
        }
    }

    Rectangle {
        id: contentWrapper

        anchors.centerIn: parent

        height: (informationContentWrapper.height) + (buttonsWrapper.height + 8)
        width: 300

        color: "black"
//        color: "#66000000"

        radius: 4

        MouseArea {
            anchors.fill: parent

            onClicked: {

            }
        }

        Rectangle {
            id: informationContentWrapper

            height: informationTextWrapper.height +imageContentWrapper.height
            width: parent.width

            color: "transparent"

            Rectangle {
                id: informationTextWrapper

                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right

                height: informationalTextValue == "" ? 0 : Style.elementHeight

                color: "transparent"

                Text {
                    id: informationalText

                    anchors.left: parent.left

                    anchors.verticalCenter: parent.verticalCenter

                    anchors.leftMargin: 4

                    width: parent.width - 6

                    horizontalAlignment: Text.AlignHCenter

                    text: informationalTextValue
                    elide: informationalTextAlignMode
                    font.pointSize: Style.elementTextSize - 1

                    color: "white"
                }
            }

            Rectangle {
                id: imageContentWrapper

                anchors.top: informationTextWrapper.bottom
                anchors.left: parent.left
                anchors.right: parent.right

                height: imagePath == "" ? 0 : parent.width

                color: "transparent"

                Rectangle {
                    id: imageWrapper

                    anchors.top: parent.top
                    anchors.bottom: imagePathWrapper.top
                    anchors.left: parent.left
                    anchors.right: parent.right

                    color: "transparent"

                    Image {
                        anchors.fill: parent

                        anchors.leftMargin: 4
                        anchors.rightMargin: 4

                        source: imagePath

                        sourceSize.width: imageWrapper.width
                        sourceSize.height: imageWrapper.height

                        asynchronous: true
                    }
                }

                Rectangle {
                    id: imagePathWrapper

                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right

                    color: "transparent"

                    height: imagePath == "" ? 0 : Style.elementHeight

                    Text {
                        id: imagePathText

                        anchors.left: parent.left

                        anchors.verticalCenter: parent.verticalCenter

                        anchors.leftMargin: 4

                        width: parent.width - 6

                        text: imagePathString
                        elide: Text.ElideMiddle
                        font.pointSize: Style.elementTextSize - 1

                        color: "white"
                    }
                }
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

                    borderColorDefault: "#26A9F7"
                    borderColorPressed: "#4FC3F7"

                    backgroundColorDefault: "#26A9F7"
                    backgroundColorPressed: "#4FC3F7"


//                    textColorDefault: "white"
//                    textColorPressed: "white"

//                    borderColorDefault: "#D50000"
//                    borderColorPressed: "#8cD50000"

//                    backgroundColorDefault: "#D50000"
//                    backgroundColorPressed: "#E53935"

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

                    borderColorDefault: "#26A9F7"
                    borderColorPressed: "#4FC3F7"

                    backgroundColorDefault: "#26A9F7"
                    backgroundColorPressed: "#4FC3F7"


//                    textColorDefault: "white"
//                    textColorPressed: "white"

//                    borderColorDefault: "#D50000"
//                    borderColorPressed: "#8cD50000"

//                    backgroundColorDefault: "#D50000"
//                    backgroundColorPressed: "#E53935"

                    text: cancelButtonText

                    onClicked: {
                        blockingComponent.cancelButtonClicked()
                    }
                }
            }
        }
    }
}
