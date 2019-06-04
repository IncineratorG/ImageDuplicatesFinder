import QtQuick 2.0

Item {
    MouseArea {
        anchors.fill: parent

        propagateComposedEvents: false

        onClicked: console.log("CLICKED")
    }

    Rectangle {
        anchors.fill: parent

        color: "#cc000000"
    }

    Component.onCompleted: console.log("BLOCKING_COMPONENT->ON_COMPLETED")
}
