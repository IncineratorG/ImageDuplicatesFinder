import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 1.4

import Style 1.0



Rectangle {
    id: inputFoldersListViewComponent

    property real numberColumnWidthFactor: 0.03
    property real folderPathColumnWidthFactor: 0.75
    property real subfolderColumnWidthFactor: 0.1
    property real actionButtonsColumnWidthFactor: -1.0

    color: "#F4F8FA"

    Rectangle {
        id: listViewTitle

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: Style.elementHeightWithMargins

        color: "transparent"

        Rectangle {
            id: numberTitleWrapper

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left

            anchors.topMargin: 4
            anchors.bottomMargin: 4
            anchors.leftMargin: 4

            width: parent.width * numberColumnWidthFactor

            color: "transparent"

            Text {
                id: numberTitleText

                anchors.left: parent.left

                anchors.leftMargin: 4

                anchors.verticalCenter: parent.verticalCenter

                width: parent.width

                text: "№"
                elide: Text.ElideRight
                font.pointSize: Style.elementTextSize + 1

                color: "#7B929C"
            }
        }

        Rectangle {
            id: folderPathTitleWrapper

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: numberTitleWrapper.right

            anchors.topMargin: 4
            anchors.bottomMargin: 4
            anchors.leftMargin: 4

            width: parent.width * folderPathColumnWidthFactor

            color: "transparent"

            Text {
                id: folderPathTitleText

                anchors.left: parent.left

                anchors.leftMargin: 8

                anchors.verticalCenter: parent.verticalCenter

                width: parent.width

                text: "Путь до папки"
                elide: Text.ElideRight
                font.pointSize: Style.elementTextSize + 1

                color: "#7B929C"
            }
        }

        Rectangle {
            id: subfolderTitleWrapper

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: folderPathTitleWrapper.right

            anchors.topMargin: 4
            anchors.bottomMargin: 4
            anchors.leftMargin: 4

            width: parent.width * subfolderColumnWidthFactor

            color: "transparent"

            Text {
                id: subfolderTitleText

                anchors.centerIn: parent

                width: parent.width

                text: "Подпапки"
                elide: Text.ElideRight
                font.pointSize: Style.elementTextSize + 1

                color: "#7B929C"
            }
        }

        Rectangle {
            id: actionButtonsTitleWrapper

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: subfolderTitleWrapper.right
            anchors.right: parent.right

            anchors.margins: 4

            color: "transparent"
        }
    }


    ListView {
        id: listView

        anchors.top: listViewTitle.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

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
            }

            Rectangle {
                id: numberWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left

                anchors.topMargin: 4
                anchors.bottomMargin: 4
                anchors.leftMargin: 4

                width: parent.width * numberColumnWidthFactor

                color: "transparent"

                Text {
                    id: numberText

                    anchors.left: parent.left

                    anchors.leftMargin: 4

                    anchors.verticalCenter: parent.verticalCenter

                    width: parent.width

                    text: model.index + 1
                    elide: Text.ElideRight
                    font.pointSize: Style.elementTextSize

                    color: "black"
                }
            }

            Rectangle {
                id: folderPathWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: numberWrapper.right

                anchors.topMargin: 4
                anchors.bottomMargin: 4
                anchors.leftMargin: 4

                width: parent.width * folderPathColumnWidthFactor

                color: "transparent"

                Text {
                    id: folderPathText

                    anchors.left: parent.left

                    anchors.leftMargin: 4

                    anchors.verticalCenter: parent.verticalCenter

                    width: parent.width

                    text: model.folderPath
                    elide: Text.ElideRight
                    font.pointSize: Style.elementTextSize + 1

                    color: "black"
                }
            }

            Rectangle {
                id: subfolderWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: folderPathWrapper.right

                anchors.topMargin: 4
                anchors.bottomMargin: 4
                anchors.leftMargin: 4

                width: parent.width * subfolderColumnWidthFactor

                color: "transparent"

                CheckBox {
                    anchors.left: parent.left

                    anchors.verticalCenter: parent.verticalCenter

                    anchors.leftMargin: 16
                }
            }

            Rectangle {
                id: actionButtonsWrapper

                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: subfolderWrapper.right
                anchors.right: parent.right

                anchors.margins: 4

                color: "transparent"

                Image {
                    id: removeButton

                    anchors.right: parent.right

                    anchors.verticalCenter: parent.verticalCenter

                    anchors.rightMargin: 4

                    width: Style.elementHeight
                    height: Style.elementHeight

                    source: "Assets/remove.png"

                    visible: listView.currentIndex == model.index

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            console.log("CLICKED")
                        }
                    }
                }
            }
        }

        model: InputFoldersModel
    }
}
