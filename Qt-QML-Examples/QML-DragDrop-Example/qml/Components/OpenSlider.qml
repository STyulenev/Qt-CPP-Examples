import QtQuick 2.15

Rectangle {
    id: panel

    signal open()

    radius: 10

    color: "lightblue"

    Rectangle {
        id: knob

        x: 5

        anchors {
            top: parent.top
            bottom: parent.bottom
            topMargin: 5
            bottomMargin: 5
        }

        height: panel.height - 10
        width: panel.height - 10

        color: "grey"

        radius: panel.radius / 2

        Drag.active: dragArea.drag.active
        Drag.hotSpot.x: 10

        MouseArea {
            id: dragArea

            anchors.fill: parent

            drag.target: parent
            drag.maximumX: panel.width - 5 - knob.width
            drag.minimumX: 5

            onReleased: (mouse) => {
                if (knob.x < (panel.width - 5 - knob.width) * 0.7) {
                    knob.x = 5
                } else {
                    knob.x = panel.width - 5 - knob.width;
                    panel.open();
                }
            }
        }

        onXChanged: {
            if (knob.x < 5)
                knob.x = 5;

            if (knob.x > panel.width - knob.width)
                knob.x = panel.width - 5 - knob.width;
        }

        Behavior on x {
            NumberAnimation {
                duration: 300
                easing.type: Easing.OutQuad
            }
        }
    }
}
