import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root

    property bool containerIsClose: false

    property alias container: container.children

    onStateChanged: {
        console.log(root.state)
    }

    RowLayout {
        id: topPanel

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            margins: 5
        }

        height: 40

        RoundButton {
            id: opanCloseButton

            Layout.fillHeight: true
            Layout.margins: 5
            Layout.preferredWidth: 80

            radius: 5

            text: root.containerIsClose ? qsTr("Close") : qsTr("Open")

            onClicked: {
                root.containerIsClose = !root.containerIsClose;
            }
        }

        ToolSeparator {
            //Layout.preferredHeight: 4
            Layout.fillWidth: true

            orientation: Qt.Horizontal
        }
    }

    Rectangle {
        id: container

        anchors {
            top: topPanel.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        clip: true

        color: "grey"
    }

    states: [
        State {
            name: "Open"
            when: root.containerIsClose

            PropertyChanges {
                target: root

                height: topPanel.height + 200
            }

            PropertyChanges {
                target: container

                visible: true
            }
        },
        State {
            name: "Close"
            when: !root.containerIsClose

            PropertyChanges {
                target: root

                height: topPanel.height
            }

            PropertyChanges {
                target: container

                visible: false
            }
        }
    ]

    transitions: [
        Transition {
            from: "Open"
            to: "Close"

            SequentialAnimation {
                NumberAnimation {
                    target: root

                    duration: 300
                    properties: "height"
                    easing.type: Easing.InOutQuad
                }

                NumberAnimation {
                    target: container

                    duration: 0
                    properties: "visible"
                    easing.type: Easing.InOutQuad
                }
            }
        },

        Transition {
            from: "Close"
            to: "Open"

            SequentialAnimation {
                NumberAnimation {
                    target: container

                    duration: 0
                    properties: "visible"
                    easing.type: Easing.InOutQuad
                }

                NumberAnimation {
                    target: root

                    duration: 300
                    properties: "height"
                    easing.type: Easing.InOutQuad
                }
            }
        }
    ]
}
