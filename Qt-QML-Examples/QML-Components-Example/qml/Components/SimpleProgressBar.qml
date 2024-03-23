import QtQuick 2.15

Rectangle {
    id: simpleProgressBar

    radius: 2.5
    color: "grey"

    property int value: 0

    MouseArea {
        id: mouseArea

        anchors.fill: parent

        onMouseXChanged: {
            if (mouseX < 0) {
                simpleProgressBarDone.width = 0;
            } else if (mouseX > simpleProgressBar.width) {
                simpleProgressBarDone.width = simpleProgressBar.width;
            } else {
                simpleProgressBarDone.width = mouseX;
            }

            simpleProgressBar.value = (simpleProgressBarDone.width / simpleProgressBar.width) * 100;
        }
    }

    Rectangle {
        id: simpleProgressBarDone

        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }

        width: simpleProgressBar.value * simpleProgressBar.width / 100
        height: parent.height
        radius: parent.radius
        color: "green"
    }
}
