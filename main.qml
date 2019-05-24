import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.5
import Style 1.0
import "UI"




ApplicationWindow {
    id: mainWindow

    visible: true
    width: 800
    height: 600
    title: qsTr("Поиск дубликатов изображений")

    MainCoordinator {
        anchors.fill: parent
    }
}



//Window {
//    id: mainWindow

//    visible: true
//    width: 1280
//    height: 720
//    title: qsTr("Поиск дубликатов изображений")

//    InputFoldersComponent {
//        id: inputFoldersComponent

//        anchors.top: parent.top
//        anchors.left: parent.left
//        anchors.right: parent.right

//        anchors.topMargin: 4
//        anchors.leftMargin: 4
//        anchors.rightMargin: 4

//        height: mainWindow.height * 0.35
//    }

//    Rectangle {
//        id: duplicateImagesListComponent

////        color: "#F4F8FA"
//        color: "grey"

//        anchors.top: inputFoldersComponent.bottom
//        anchors.bottom: controlButtonsComponent.top
//        anchors.left: parent.left
//        anchors.right: parent.right

//        anchors.margins: 4
//    }

//    Rectangle {
//        id: controlButtonsComponent

//        color: "grey"

//        anchors.bottom: parent.bottom
//        anchors.left: parent.left
//        anchors.right: parent.right

//        anchors.bottomMargin: 4
//        anchors.leftMargin: 4
//        anchors.rightMargin: 4

//        height: Style.elementHeight
//    }
//}































//import QtQuick 2.12
//import QtQuick.Window 2.12

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello")
//}
