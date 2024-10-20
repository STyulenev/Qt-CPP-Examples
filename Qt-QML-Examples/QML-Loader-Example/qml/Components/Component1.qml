import QtQuick

Rectangle {
    id: root

    signal message(string msg)

    anchors.fill: parent

    color: "blue"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.message("clicked 1!")
            root.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
        }
    }
}
