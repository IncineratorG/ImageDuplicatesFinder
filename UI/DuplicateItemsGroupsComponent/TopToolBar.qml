import QtQuick 2.12
import QtQuick.Controls 2.12
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
        id: topBorderLine

        anchors.bottom: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: 1

        color: "#F4F8FA"
    }

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
        anchors.right: comboBoxWrapper.left

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
        id: comboBoxWrapper

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        width: 120

        color: "transparent"

        // ===
        ComboBox {
            id: control

            anchors.fill: parent

            anchors.bottomMargin: 1
            anchors.rightMargin: 1

            model: ResultViewTypesModel

            currentIndex: ResultViewTypesModel.currentIndex
            onCurrentIndexChanged: {
                ResultViewTypesModel.currentIndex = currentIndex
            }

            delegate: ItemDelegate {
                width: control.width
                contentItem: Text {
                    text: modelData
//                    color: "#21be2b"
                    color: "grey"
                    font: control.font
                    elide: Text.ElideRight
                    verticalAlignment: Text.AlignVCenter
                }
                highlighted: control.highlightedIndex === index
            }

            indicator: Canvas {
                id: canvas
                x: control.width - width - control.rightPadding
                y: control.topPadding + (control.availableHeight - height) / 2
                width: 10
                height: 6
                contextType: "2d"

                Connections {
                    target: control
                    onPressedChanged: canvas.requestPaint()
                }

                onPaint: {
                    context.reset();
                    context.moveTo(0, 0);
                    context.lineTo(width, 0);
                    context.lineTo(width / 2, height);
                    context.closePath();
                    context.fillStyle = control.pressed ? "black" : "grey";
                    context.fill();
                }
            }

            contentItem: Text {
                leftPadding: 4
                rightPadding: control.indicator.width + control.spacing

                text: control.displayText
                font: control.font
                color: control.pressed ? "black" : "black"
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 120
                implicitHeight: 40
                border.color: control.pressed ? "black" : "grey"
                border.width: control.visualFocus ? 2 : 1
                radius: 2
            }

            popup: Popup {
                y: control.height - 1
                width: control.width
                implicitHeight: contentItem.implicitHeight
                padding: 1

                contentItem: ListView {
                    clip: true
                    implicitHeight: contentHeight
                    model: control.popup.visible ? control.delegateModel : null
                    currentIndex: control.highlightedIndex

                    ScrollIndicator.vertical: ScrollIndicator { }
                }

                background: Rectangle {
                    border.color: "grey"
                    radius: 2
                }
            }
        }
        // ===
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








//Rectangle {
//    id: topToolBarWrapper

//    property string toolBarText: ""
//    property bool leftButtonVisible: true
//    property bool rightButtonVisible: true

//    signal leftButtonClicked()
//    signal rightButtonClicked()

//    height: visible ? Style.elementHeight : 0

//    color: "transparent"

//    Rectangle {
//        id: topBorderLine

//        anchors.bottom: parent.top
//        anchors.left: parent.left
//        anchors.right: parent.right

//        height: 1

//        color: "#F4F8FA"
//    }

//    Rectangle {
//        id: leftButtonWrapper

//        anchors.top: parent.top
//        anchors.bottom: parent.bottom
//        anchors.left: parent.left

//        width: 30

//        color: "transparent"

//        visible: leftButtonVisible

//        MouseArea {
//            anchors.fill: parent

//            onPressed: {
//                leftButtonWrapper.color = "#F4F8FA"
//            }

//            onReleased: {
//                leftButtonWrapper.color = "transparent"
//            }

//            onClicked: {
//                leftButtonClicked()
//            }
//        }

//        Image {
//            anchors.fill: parent

//            anchors.margins: 4

//            source: "../Assets/left_arrow.png"
//        }

//        Rectangle {
//            id: leftButtonWrapperRightSeparatorLine

//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            anchors.right: parent.right

//            width: 1

//            color: "#F4F8FA"
//        }
//    }

//    Rectangle {
//        id: toolBarTextWrapper

//        anchors.top: parent.top
//        anchors.bottom: parent.bottom
//        anchors.left: leftButtonWrapper.right
//        anchors.right: rightButtonWrapper.left

//        color: "transparent"

//        Text {
//            anchors.verticalCenter: parent.verticalCenter
//            anchors.horizontalCenter: parent.horizontalCenter

//            width: parent.width

//            horizontalAlignment: Text.AlignHCenter

//            text: toolBarText
//            elide: Text.ElideRight
//            font.pointSize: 12

//            color: "black"
//            opacity: 0.7
//        }
//    }

//    Rectangle {
//        id: rightButtonWrapper

//        anchors.top: parent.top
//        anchors.bottom: parent.bottom
//        anchors.right: parent.right

//        width: 30

//        color: "transparent"

//        visible: rightButtonVisible

//        MouseArea {
//            anchors.fill: parent

//            onPressed: {
//                rightButtonWrapper.color = "#F4F8FA"
//            }

//            onReleased: {
//                rightButtonWrapper.color = "transparent"
//            }

//            onClicked: {
//                rightButtonClicked()
//            }
//        }

//        Image {
//            anchors.fill: parent

//            anchors.margins: 4

//            source: "../Assets/right_arrow.png"
//        }

//        Rectangle {
//            id: rightButtonWrapperLeftSeparatorLine

//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            anchors.left: parent.left

//            width: 1

//            color: "#F4F8FA"
//        }
//    }

//    Rectangle {
//        id: bottomBorderLine

//        anchors.bottom: parent.bottom
//        anchors.left: parent.left
//        anchors.right: parent.right

//        height: 1

//        color: "#F4F8FA"
//    }
//}
