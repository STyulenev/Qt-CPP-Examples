import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.6

import Components 1.0 as Components

ApplicationWindow {
    id: mainWindow

    width: 480
    height: 320
    visible: true
    title: qsTr("QML-DragDrop-Example")

    TabBar {
        id: tabBar

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }

        TabButton {
            text: qsTr("ScrollingContainer")
        }

        TabButton {
            text: qsTr("DraggableRectangle")
        }

        TabButton {
            text: qsTr("OpenSlider")
        }
    }

    StackLayout {
        id: stackLayout

        anchors {
            top: tabBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        currentIndex: tabBar.currentIndex

        Item {
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

        Item {
            Components.DraggableRectangle {
                id: draggableRectangle

                x: 10
                y: 10

                width: 100
                height: 100
            }
        }

        Item {
            Components.OpenSlider {
                id: openSlider

                anchors.centerIn: parent

                width: 400
                height: 80

                onOpen: {
                    console.log("OK")
                }
            }
        }
    }
}
