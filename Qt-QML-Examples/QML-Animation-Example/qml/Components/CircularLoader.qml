import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    id: root

    property real value: 0
    required property int size

    width: root.size
    height: root.size

    Timer {
        id: timer

        interval: 20
        running: true
        repeat: true

        onTriggered: {
            if (value < 100.0) {
                value = value + 0.2;
                rotation.angle = rotation.angle + 1;
            } else {
                timer.stop();
            }
        }
    }

    Label {
        id: title

        anchors.centerIn: parent
        z: 2
        text: Math.floor(value) + "%"
    }

    Rectangle {
        id: rectangle
        anchors.fill: parent


        radius: root.size / 2

        color: "blue"
        transform: Rotation {
            id: rotation

            origin.x: rectangle.width / 2
            origin.y: rectangle.height / 2
            angle: 0
        }

        Shape {
            id: progressShape

            anchors.fill: parent
            anchors.margins: 10
            layer.enabled: true
            layer.samples: 8
            visible: true

            ShapePath {
                id: progressShapePath

                strokeColor: "green"
                fillColor: "transparent"
                strokeWidth: 20
                capStyle: ShapePath.RoundCap

                PathAngleArc {
                    id: path

                    radiusX: 130
                    radiusY: 130
                    centerX: progressShape.width / 2
                    centerY: progressShape.height / 2
                    startAngle: 0
                    sweepAngle: (value / 100) * 360
                }
            }
        }
    }
}
