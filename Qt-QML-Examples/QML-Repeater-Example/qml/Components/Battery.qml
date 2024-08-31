import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root

    required property int orientation

    border {
        id: borderRoot
        color: root.currentColor()
        width: 5
    }

    radius: 10
    color: "transparent"

    property int count: 4
    property int charge: 0
    property int currentValue: 0

    function getColorForIndex(index) {
        if (root.currentValue > index) {
            return "transparent";
        } else {
            return currentColor();
        }
    }

    function currentColor() {
        if (charge >= 75)
            return "green";
        if (charge >= 50)
            return "orange";
        if (charge >= 25)
            return "red";

        return "darkred";
    }

    onChargeChanged: {
        if (root.charge < 0)
            root.charge = 0;

        if (root.charge > 100)
            root.charge = 100;

        if (root.count <= 0) {
            return;
        } else {
            currentValue = count - Math.round(charge / (100 / count));
        }
    }

    Column {
        id: column

        property int margins: borderRoot.width * 2

        anchors.fill: parent
        anchors.margins: column.margins
        spacing: 5
        z: 2
    }

    Row {
        id: row

        property int margins: borderRoot.width * 2

        anchors.fill: parent
        anchors.margins: row.margins
        spacing: 5
        z: 2
    }

    Repeater {
        id: repeater

        model: root.count
        delegate: Rectangle {
            radius: root.radius / 2

            width: root.orientation === Qt.Horizontal ?
                       (parent.width - parent.spacing * (root.count) + borderRoot.width) / root.count : parent.width
            height: root.orientation === Qt.Horizontal ?
                        parent.height : (parent.height - parent.spacing * (root.count) + borderRoot.width) / root.count
            color: root.getColorForIndex(index)
        }
    }

    states: [
        State {
            name: "Horizontal"
            when: root.orientation === Qt.Horizontal

            ParentChange {
                target: repeater

                parent: row
            }

            AnchorChanges {
                target: repeater

                anchors {
                    left: row.left
                    right: row.right
                    top: row.top
                    bottom: row.bottom
                }
            }

            PropertyChanges {
                target: row

                visible: true
            }

            PropertyChanges {
                target: column

                visible: false
            }
        },
        State {
            name: "Vertical"
            when: root.orientation === Qt.Vertical

            ParentChange {
                target: repeater

                parent: column
            }

            AnchorChanges {
                target: repeater

                anchors {
                    left: column.left
                    right: column.right
                    top: column.top
                    bottom: column.bottom
                }
            }

            PropertyChanges {
                target: row

                visible: false
            }

            PropertyChanges {
                target: column

                visible: true
            }
        }
    ]
}
