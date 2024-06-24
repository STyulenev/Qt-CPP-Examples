import QtQuick 2.15

Rectangle {
    id: root

    color: "red"

    Drag.active: dragArea.drag.active
    Drag.hotSpot.x: 10
    Drag.hotSpot.y: 10

    MouseArea {
        id: dragArea

        anchors.fill: parent
        drag.target: parent

        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: (mouse) => {
            root.color =  (mouse.button === Qt.LeftButton) ? "blue" : "red";
        }
    }

    focus: true

    Keys.onPressed: (event) => {
        switch (event.key) {
        case Qt.Key_Up:
            root.y -= 10;
            break;
         case Qt.Key_Down:
           root.y += 10;
            break;
        case Qt.Key_Left:
            root.x -= 10;
            break;
        case Qt.Key_Right:
            root.x += 10;
            break;
        }
    }
}
