import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

TreeView {
    id: control

    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AlwaysOff
    }

    ScrollBar.horizontal: ScrollBar {
        policy: ScrollBar.AlwaysOff
    }

    delegate: Item {
        id: root

        implicitWidth: padding + label.x + label.implicitWidth + padding
        implicitHeight: label.implicitHeight * 1.5

        readonly property real indent: 20
        readonly property real padding: 5
        required property bool isTreeNode
        required property bool expanded
        required property int hasChildren
        required property int depth

        TapHandler {
            onTapped: {
                console.log(row + " " + column)
                control.toggleExpanded(row)
            }
        }

        Canvas {
            id: canvas

            visible: root.isTreeNode && root.hasChildren
            x: padding + (root.depth * root.indent)

            width: 10
            height: 10
            rotation: root.expanded ? -90 : 0

            onPaint: {
                var context = getContext("2d");
                context.reset();
                context.moveTo(0, 0);
                context.lineTo(width, 0);
                context.lineTo(width / 2, height);
                context.closePath();
                context.fillStyle = "#000000";
                context.fill();
            }
        }

        Text {
            id: label
            x: padding + (root.isTreeNode ? (root.depth + 1) * root.indent : 0)
            width: root.width - root.padding - x
            clip: true
            text: model.display

            font {
                pixelSize: 12
                family: "Verdana"
                weight: Font.Bold
            }
        }
    }
}
