import QtQuick 2.11

Item {
    id: root

    signal statusWasChanged(bool value)

    readonly property color backgroundFirstColor: "skyblue"
    readonly property color backgroundSecondColor: "darkblue"

    readonly property color knobFirstColor: "yellow"
    readonly property color knobSecondColor: "grey"

    property bool status: true
    property int duration: 500

    state: root.status ? "on" : "off";

    function changeState() {
        if (root.state === "on")
            root.state = "off";
        else
            root.state = "on";

        root.statusWasChanged(root.status);
    }

    Rectangle {
        id: background

        anchors.fill: parent
        radius: parent.height / 2

        MouseArea {
            anchors.fill: parent

            onClicked: {
                root.changeState();
            }
        }

        Rectangle {
            id: knob
            width: parent.height * 0.9
            height: parent.height * 0.9
            radius: parent.height * 0.9
            y: ((root.height * 10) / 100) / 2
        }
    }

    states: [
        State {
            name: "on"

            PropertyChanges {
                target: knob
                x: ((root.width * 5) / 100) / 2
            }
            PropertyChanges {
                target: knob
                color: root.knobFirstColor
            }

            PropertyChanges {
                target: background
                color: root.backgroundFirstColor
            }
            PropertyChanges {
                target: root
                status: true
            }
        },
        State {
            name: "off"

            PropertyChanges {
                target: knob
                x: root.width - knob.width - ((root.width * 5) / 100) / 2
            }
            PropertyChanges {
                target: knob
                color: root.knobSecondColor
            }
            PropertyChanges {
                target: background
                color: root.backgroundSecondColor
            }
            PropertyChanges {
                target: root
                status: false
            }
        }
    ]

    transitions: [
        Transition {
            from: "on"
            to: "off"
            reversible: true

            ParallelAnimation {
                ColorAnimation {
                    target: background
                    duration: root.duration
                }

                ColorAnimation {
                    target: knob
                    duration: root.duration
                }

                NumberAnimation {
                    target: knob
                    duration: root.duration
                    properties: "x"
                    easing.type: Easing.InOutQuad
                }
            }
        },
        Transition {
            from: "off"
            to: "on"
            reversible: true

            ParallelAnimation {
                ColorAnimation {
                    target: background
                    duration: root.duration
                }

                ColorAnimation {
                    target: knob
                    duration: root.duration
                }

                NumberAnimation {
                    target: knob
                    duration: root.duration
                    properties: "x"
                    easing.type: Easing.InOutQuad
                }
            }
        }
    ]
}
