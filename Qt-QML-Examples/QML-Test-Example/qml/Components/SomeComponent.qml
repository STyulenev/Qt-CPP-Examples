import QtQuick 2.11
import QtQuick.Controls 2.4

Rectangle {
    id: root

    color: "#d3d3d3"
    width: 200
    height: 200
    radius: 5

    signal clicked

    property int value: 0

    onClicked: {
        root.value++;
    }

    Label {
        id: label

        objectName: "label"

        anchors.centerIn: parent

        font.pixelSize: 24
        color: "black"
        text: root.value;
    }

    MouseArea {
        id: mouseArea

        objectName: "mouseArea"

        anchors.fill: parent

        onClicked: {
            root.clicked();
        }
    }
}
