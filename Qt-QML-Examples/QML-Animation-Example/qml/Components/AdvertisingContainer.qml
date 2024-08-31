import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root

    radius: 2
    border.color: "black"

    clip: true

    state: "down"
    property alias title: title.text

    Label {
        id: title

        anchors.centerIn: parent

        z: 2
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        hoverEnabled: true

        z: 3

        onEntered: {
            root.state = "up";
        }

        onExited: {
            root.state = "down";
        }
    }

    Rectangle {
        id: panel

        anchors {
            left: parent.left
            right: parent.right
        }

        height: 100
        width: parent.width

        color: "grey"
        opacity: 0.5
    }

    states: [
        State {
            name: "up"

            PropertyChanges {
                target: title
                font.pixelSize: 25
            }

            PropertyChanges {
                target: panel
                y: root.height - panel.height
            }
        },
        State {
            name: "down"

            PropertyChanges {
                target: title
                font.pixelSize: 15
            }

            PropertyChanges {
                target: panel
                y: root.height
            }
        }
    ]

    transitions: [
        Transition {
            from: "up"
            to: "down"

            ParallelAnimation {
                NumberAnimation {
                    target: title
                    properties: "font.pixelSize"
                    duration: 500
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: panel
                    properties: "y"
                    duration: 500
                    easing.type: Easing.InOutQuad
                }
            }
        },
        Transition {
            from: "down"
            to: "up"

            ParallelAnimation {
                NumberAnimation {
                    target: title
                    properties: "font.pixelSize"
                    duration: 500
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: panel
                    properties: "y"
                    duration: 500
                    easing.type: Easing.InOutQuad
                }
            }
        }
    ]
}
