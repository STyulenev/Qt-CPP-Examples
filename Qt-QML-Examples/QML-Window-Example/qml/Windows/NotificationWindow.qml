import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: root

    x: Screen.width - root.width - 20
    y: Screen.height - root.height - 60

    width: 300
    height: 150

    flags: Qt.FramelessWindowHint | Qt.Dialog
    visible: true

    menuBar: null

    color: "transparent"

    function setNotification(data) {
        title.text = data;
        timer.start();
    }

    Timer {
        id: timer

        interval: 3000
        running: false
        repeat: false

        onTriggered: {
            // ...
        }
    }

    Rectangle {
        id: panel

        anchors.fill: parent

        radius: 5

        color: "lightblue"
        visible: timer.running

        Label {
            id: title

            anchors.centerIn: parent
        }
    }
}
