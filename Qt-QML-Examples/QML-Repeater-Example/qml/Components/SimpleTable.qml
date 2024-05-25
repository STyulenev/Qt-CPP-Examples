import QtQuick 2.15

Item {
    id: root

    property int column: 3

    Repeater {
        id: repeater

        anchors.fill: parent

        model: 6

        delegate: Rectangle {
            property int row: Math. floor (index / 3)
            property int column: index % root.column

            width: root.width / root.column
            height: 40

            border.width: 1
            color: "yellow"

            x: column * width
            y: row * height

            Text {
                anchors.centerIn: parent
                text: "Row: " + parent.row + " Column: " + parent.column
            }
        }
    }
}
