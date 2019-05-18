import QtQuick 2.0
import QtQuick.Controls 2.1

import Style 1.0

Button {
    id: button

    property string textColorDefault: "black"
    property string textColorHovered: textColorDefault
    property string textColorPressed: "white"

    property string backgroundColorDefault: "white"
    property string backgroundColorHovered: backgroundColorDefault
    property string backgroundColorPressed: "grey"

    property string borderColorDefault: "grey"
    property string borderColorHovered: borderColorDefault
    property string borderColorPressed: "white"

    property var textPointSize: Style.elementTextSize

    contentItem: Text {
        text: button.text
        font.family: "Helvetica"
        font.pointSize: textPointSize
        opacity: enabled ? 1.0 : 0.3
        color: button.pressed ? textColorPressed :
               button.hovered ? textColorHovered :
                                textColorDefault
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: button.pressed ? borderColorPressed :
                      button.hovered ? borderColorHovered :
                                       borderColorDefault
        border.width: 1
        radius: 2

        color: button.pressed ? backgroundColorPressed :
               button.hovered ? backgroundColorHovered :
                                backgroundColorDefault

    }
}
