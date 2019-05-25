import QtQuick 2.12
import "Assets"



Rectangle {
    id: waitComponent

    color: "#cc000000"

    z: 100

    Rectangle {
        anchors.centerIn: parent

        height: 150
        width: 150

        color: "#66000000"

        radius: 4

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
}
