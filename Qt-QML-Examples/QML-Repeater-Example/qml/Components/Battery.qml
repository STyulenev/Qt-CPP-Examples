import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle {
    id: root

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

        Repeater {
            model: root.count
            delegate: Rectangle {
                radius: root.radius / 2
                anchors {
                    left: parent.left
                    right: parent.right
                }

                width: column.width * (index + 1)
                height: (column.height - column.spacing * (root.count) + borderRoot.width) / root.count
                color: root.getColorForIndex(index)
            }
        }
    }
}
