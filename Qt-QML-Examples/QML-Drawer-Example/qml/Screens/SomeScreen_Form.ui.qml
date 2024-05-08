import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: formSomeScreen

    signal menuButton1Clicked()
    signal menuButton2Clicked()

    readonly property int headerSize: 50

    Rectangle {
        id: header

        height: headerSize
        color: "lightgrey"

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        Row {
            anchors.fill: parent
            anchors.margins: 10

            Button {
                id: menuButton1

                text: qsTr("Standart Drawer")

                height: 40
                width: 100

                Connections {
                    target: menuButton1

                    function onClicked() {
                        formSomeScreen.menuButton1Clicked();
                    }
                }
            }

            Button {
                id: menuButton2

                text: qsTr("Custom Drawer")

                height: 40
                width: 100

                Connections {
                    target: menuButton2

                    function onClicked() {
                        formSomeScreen.menuButton2Clicked();
                    }
                }
            }
        }
    }
}
