import QtQuick 2.11
import QtQuick.Window 2.11

import Style 1.0



Window {
    id: mainWindow

    visible: true
    width: 1280
    height: 720
    title: qsTr("Поиск дубликатов изображений lll")

    InputFoldersComponent {
        id: inputFoldersComponent

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.topMargin: 4
        anchors.leftMargin: 4
        anchors.rightMargin: 4

        height: mainWindow.height * 0.35
    }

    Rectangle {
        id: duplicateImagesListComponent

//        color: "#F4F8FA"
        color: "grey"

        anchors.top: inputFoldersComponent.bottom
        anchors.bottom: controlButtonsComponent.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 4
    }

    Rectangle {
        id: controlButtonsComponent

        color: "grey"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.bottomMargin: 4
        anchors.leftMargin: 4
        anchors.rightMargin: 4

        height: Style.elementHeight
    }










//    UIButton {
//        id: startButton

//        anchors.bottom: parent.bottom
//        anchors.left: parent.left

//        anchors.bottomMargin: 4
//        anchors.leftMargin: 4

//        height: Style.elementHeight
//        width: parent.width / 2 - 4

//        text: "Start"

//        onClicked: DuplicateImagesListModelsManager.start()
//    }

//    UIButton {
//        id: stopButton

//        anchors.bottom: parent.bottom
//        anchors.left: startButton.right
//        anchors.right: parent.right

//        anchors.bottomMargin: 4
//        anchors.leftMargin: 4
//        anchors.rightMargin: 4

//        height: Style.elementHeight

//        text: "Stop"

//        onClicked: DuplicateImagesListModelsManager.stop()
//    }
}































//import QtQuick 2.12
//import QtQuick.Window 2.12

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello")
//}
