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

    // Standart MenuBar
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")

            Action {
                text: qsTr("New")

                onTriggered: {
                    console.log("New");
                }
            }

            Action {
                text: qsTr("Open")

                onTriggered: {
                    console.log("Open");
                }
            }

            Action {
                text: qsTr("Save")

                onTriggered: {
                    console.log("Save");
                }
            }

            MenuSeparator { }

            Action {
                text: qsTr("Quit")

                onTriggered: {
                    console.log("Quit");
                }
            }
        }

        MenuSeparator { }

        Menu {
            title: qsTr("Help")

            Action {
                text: qsTr("About")

                onTriggered: {
                    console.log("About");
                }
            }
        }
    }

    Rectangle {
        id: testArea

        anchors.centerIn: parent
        height: 100
        width: 100
        color: "lightgrey"

        MouseArea {
            id: mouseArea

            focus: true
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            Connections {
                target: mouseArea

                function onClicked(mouse) {
                    if (mouse.button === Qt.RightButton)
                        firstContextMenu.popup();
                }

                function onPressAndHold(mouse) {
                    if (mouse.button === Qt.LeftButton) {
                        secondContextMenu.x = testArea.x + mouse.x;
                        secondContextMenu.y = testArea.y + mouse.y;
                        secondContextMenu.open();
                    }
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
                console.log("Copy");
            }
        }

        MenuItem {
            text: "Paste"
            onTriggered: {
                console.log("Paste");
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
                    console.log("Quit");
                    secondContextMenu.close();
                }
            }

            Button {
                text: "Restart"
                width: 100
                height: 20
                onClicked: {
                    console.log("Restart");
                    secondContextMenu.close();
                }
            }
        }
    }
}
