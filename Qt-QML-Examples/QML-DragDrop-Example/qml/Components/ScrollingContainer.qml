import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: container

    property int rightBorder: 400
    property alias content: body.children

    clip: true

    Row {
        id: body

        z: 2

        onXChanged: {
            if (body.x > 0)
                body.x = 0;

            if (body.x < - container.rightBorder)
                body.x = - container.rightBorder;
        }

        anchors {
            top: parent.top
            bottom: parent.bottom
        }
    }

    MouseArea {
        z: 1

        anchors.fill: parent

        drag.target: body

        acceptedButtons: Qt.LeftButton | Qt.RightButton
    }
}
