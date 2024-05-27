import QtQuick 2.15

import Models 1.0 as Models

Item {
    id: root

    property QtObject model: Models.SimpleTableModel { }

    onModelChanged: {
        repeater.update();
    }

    Repeater {
        id: repeater

        anchors.fill: parent

        model: root.model.length

        delegate: Rectangle {
            id: delegate

            property int row: Math.floor(index / root.model.column)
            property int column: index % root.model.column

            width: root.width / root.model.column
            height: 40

            border.width: 1
            color: "transparent"

            x: delegate.column * delegate.width
            y: delegate.row * delegate.height

            Text {
                id: text

                anchors.centerIn: parent

                text: root.model.myArray[index]
            }
        }
    }
}
