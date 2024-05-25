import QtQuick 2.11

Item {
    id: root

    signal valueChanged(string value)

    readonly property color firstColor: "green"
    readonly property color secondColor: "red"

    state: "topNLeft"

    function changeState(x, y) {
        if (x < (background.width / 2)) {
            root.state = (y < (background.height / 2)) ? "topNLeft" : "bottomNLeft";
        } else {
            root.state = (y < (background.height / 2)) ? "topNRight" : "bottomNRight";
        }

        /*switch(root.state) {
        case "topNleft":
            root.state = "topNRight";
            break;
        case "topNRight":
            root.state = "bottomNRight";
            break;
        case "bottomNRight":
            root.state = "bottomNLeft";
            break;
        case "bottomNLeft":
            root.state = "topNLeft";
            break;
        }*/

        root.valueChanged(root.state);
    }

    Rectangle {
        id: background

        anchors.fill: parent

        radius: 10
        color: "grey"

        MouseArea {
            anchors.fill: parent

            onClicked: (mouse) => {
                root.changeState(mouse.x,  mouse.y);
            }
        }

        Rectangle {
            id: knob

            width: parent.height / 2
            height: parent.height / 2
            radius: 10

            color: "green"
        }
    }

    states: [
        State {
            name: "topNLeft"

            AnchorChanges {
                target: knob

                anchors {
                    left: background.left
                    top: background.top
                }
            }
        },
        State {
            name: "bottomNLeft"

            AnchorChanges {
                target: knob

                anchors {
                    left: background.left
                    bottom: background.bottom
                }
            }
        },
        State {
            name: "topNRight"

            AnchorChanges {
                target: knob

                anchors {
                    right: background.right
                    top: background.top
                }
            }
        },
        State {
            name: "bottomNRight"

            AnchorChanges {
                target: knob

                anchors {
                    right: background.right
                    bottom: background.bottom
                }
            }
        }
    ]

    transitions: Transition {
        AnchorAnimation {
            duration: 500
            easing.type: Easing.OutCubic;
        }
    }
}
