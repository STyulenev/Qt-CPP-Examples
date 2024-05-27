import QtQuick
import QtQuick.Shapes

Item {
    id: root

    property int count
    property int value
    property int size

    function getColorForIndex(index) {
        return (root.value > index) ? "grey" : "darkBlue";
    }

    height: root.size
    width: root.size / 2

    Repeater {
        model: root.count

        delegate: Shape {
            id: shape

            x: 0
            y: 0

            layer {
                //enabled: true
                samples: 4
            }

            ShapePath {
                id: shapePath

                fillColor: "transparent"
                strokeColor: root.getColorForIndex(index)
                strokeWidth: 10
                capStyle: ShapePath.RoundCap

                PathAngleArc {
                    centerX: 0
                    centerY: root.height / 2
                    radiusX: Math.abs((root.width - shapePath.strokeWidth / 2) - 15 * index)
                    radiusY: Math.abs((root.width - shapePath.strokeWidth/ 2) - 15 * index)
                    startAngle: -70 + 5 * index
                    sweepAngle: 140 - 10 * index
                }
            }
        }
    }
}
