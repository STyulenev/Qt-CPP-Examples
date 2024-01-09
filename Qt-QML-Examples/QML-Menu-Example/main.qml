import QtQuick
import QtQuick.Window
import QtQuick.Controls

ApplicationWindow {
    id: applicationWindow

    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Menu-Example")

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
    }

    Connections {
        target: mouseArea

        function onClicked(mouse) {
            if (mouse.button === Qt.RightButton)
                firstContextMenu.popup()
        }
    }

    Menu {
        id: firstContextMenu

        MenuItem {
            text: "Cut"
            onTriggered: {
                console.log("Cut")
            }
        }

        MenuItem {
            text: "Copy"
            onTriggered: {
                console.log("Copy")
            }
        }

        MenuItem {
            text: "Paste"
            onTriggered: {
                console.log("Paste")
            }
        }
    }
}
