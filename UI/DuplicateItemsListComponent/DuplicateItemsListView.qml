import QtQuick 2.0



Rectangle {
    id: duplicateItemsListViewComponent

    color: "#F4F8FA"

    ListView {
        id: listView

        anchors.fill: parent

        spacing: 4

        clip: true

        delegate: Rectangle {
            id: itemDelegate

            width: parent.width
            height: 40

            color: "#E9F4FA"
        }

//        model: DuplicatesListModel
    }
}
