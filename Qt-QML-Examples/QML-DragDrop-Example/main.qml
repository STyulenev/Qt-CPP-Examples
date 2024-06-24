import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Components 1.0 as Components

ApplicationWindow {
    id: mainWindow

    width: 480
    height: 320
    visible: true
    title: qsTr("QML-DragDrop-Example")

    Components.ScrollingContainer {
        id: container

        anchors.centerIn: parent

        width: 200
        height: 200

        rightBorder: 400

        content: Repeater {
            model: [
                {
                    color: "lightblue",
                    text: "1 =>"
                },
                {
                    color: "grey",
                    text: "<= 2 =>"
                },
                {
                    color: "lightgrey",
                    text: "<= 3"
                }
            ]

            delegate: Rectangle {
                width: 200
                height: container.height

                color: modelData.color

                Label {
                    anchors.centerIn: parent
                    font.pixelSize: 28
                    color: "black"
                    text: modelData.text
                }
            }
        }
    }
}
