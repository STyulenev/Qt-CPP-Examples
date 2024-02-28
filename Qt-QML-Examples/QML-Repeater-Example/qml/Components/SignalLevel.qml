import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Row {
    id: root
    anchors.centerIn: parent
    spacing: 5

    property int count: 4
    property int currentValue: 0

    onCurrentValueChanged: {
        if (root.currentValue < 0)
            root.currentValue = 0;

        if (root.currentValue > root.count - 1)
            root.currentValue = root.count - 1;
    }

    Repeater {
        model: root.count
        delegate: Rectangle {
            radius: 5
            anchors {
                bottom: parent.bottom
            }

            width:  (root.width - root.spacing * (count - 1)) / count
            height: root.height * ((index + 1) * 0.25)
            color: (currentValue <= index) ? "grey" : "green"
        }
    }
}

