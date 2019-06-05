import QtQuick 2.0



Item {
    id: menuComponent

    visible: false
    z: visible ? 10 : -1

    width: 100
    height: 80

    function show(x, y) {
        menuComponent.x = x
        menuComponent.y = y
        menuComponent.visible = true
    }

    function hide() {
        menuComponent.visible = false
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            console.log("ON_MENU_CLICKED")
        }
    }

    Rectangle {
        anchors.fill: parent

        color: "salmon"
    }
}
