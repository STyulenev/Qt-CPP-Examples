import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: applicationWindow

    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Menu-Example")

    MouseArea {
        id: mouseArea
        focus: true
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        Connections {
            target: mouseArea

            function onClicked(mouse) {
                if (mouse.button === Qt.RightButton)
                    firstContextMenu.popup()
            }

            function onPressAndHold(mouse) {
                if (mouse.button === Qt.LeftButton) {
                    secondContextMenu.x = mouse.x;
                    secondContextMenu.y = mouse.y;
                    secondContextMenu.open();
                }
            }
        }
    }

    // Standart Menu
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

    // Custom Popup Menu
    Popup {
        id: secondContextMenu
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        RowLayout {
            anchors.fill: parent

            Button {
                text: "Quit"
                width: 100
                height: 20
                onClicked: {
                    console.log("Quit")
                    secondContextMenu.close()
                }
            }

            Button {
                text: "Restart"
                width: 100
                height: 20
                onClicked: {
                    console.log("Restart")
                    secondContextMenu.close()
                }
            }
        }
    }
}
