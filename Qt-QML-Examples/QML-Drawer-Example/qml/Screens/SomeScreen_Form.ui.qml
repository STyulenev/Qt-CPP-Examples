import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: formSomeScreen

    signal menuButtonClicked

    readonly property int headerSize: 48

    Rectangle {
        id: header

        height: headerSize
        color: "lightgrey"

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        Button {
            id: menuButton
            width: headerSize
            text: qsTr("Menu")
            anchors {
                bottom: parent.bottom
                left: parent.left
                top: parent.top
            }

            Connections {
                target: menuButton

                function onClicked() {
                    formSomeScreen.menuButtonClicked();
                }
            }
        }
    }
}
