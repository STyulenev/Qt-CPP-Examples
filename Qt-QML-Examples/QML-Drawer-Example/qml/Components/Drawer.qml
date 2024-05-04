import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: root

    anchors.fill: parent

    x: parent.x
    y: parent.y

    property int size: 200

    property int position: Qt.AlignTop
    property bool menuIsShown: false

    property int durationOfMenuAnimation: 500
    property int menuWidth: parent.width

    property real menuProgressOpening: 0
    property int stateY

    property alias content: menuRectangle.children

    function onMenu() { // изменение местоположения
        switch (position) {
        case Qt.AlignTop:
            menuRectangle.y = root.menuIsShown ? -root.size : 0;
            break;
        case Qt.AlignBottom:
            menuRectangle.y = root.menuIsShown ? root.height : root.height - root.size;
            break;
        case Qt.AlignLeft:
            menuRectangle.x = root.menuIsShown ? -root.size : 0;
            break;
        case Qt.AlignRight:
            menuRectangle.x = root.menuIsShown ? root.width : root.width - root.size;
            break;
        default:
            console.log("error")
        }

        root.menuIsShown = !root.menuIsShown;
    }

    Rectangle {
        id: menuRectangle

        z: 2
        color: 'lightblue'

        Component.onCompleted: {
            stateY = menuRectangle.y
            root.menuProgressOpening = 0
        }

        Behavior on y {
            NumberAnimation {
                duration: root.durationOfMenuAnimation;
                easing.type: Easing.OutQuad
            }
        }

        Behavior on x {
            NumberAnimation {
                duration: root.durationOfMenuAnimation;
                easing.type: Easing.OutQuad
            }
        }

        onYChanged: {
            switch(position) {
            case Qt.AlignTop:
                menuProgressOpening = Math.abs(0.5 + (menuRectangle.y / (2 * root.size)));
                break;
            case Qt.AlignBottom:
                menuProgressOpening = Math.abs(1 - (menuRectangle.y - (root.height - root.size)) / (root.height - (root.height - root.size))) * 0.5;
                break;
            default:
                console.log("error")
            }
        }

        onXChanged: {
            switch(position) {
            case Qt.AlignLeft:
                menuProgressOpening = Math.abs((menuRectangle.x + root.size) / (- root.size)) * 0.5;
                break;
            case Qt.AlignRight:
                menuProgressOpening = Math.abs(1 - (menuRectangle.x - (root.width - root.size)) / (root.width - (root.width - root.size))) * 0.5;
                break;
            default:
                console.log("error")
            }
        }
    }

    Rectangle {
        id: backgroundRectangle

        z: 1

        anchors.fill: parent
        color: "black"
        opacity: root.menuProgressOpening
    }

    MouseArea {
        id: dragRectangle
        z: 2
        enabled: root.menuIsShown

        onClicked: {
            if (root.menuIsShown)
                root.onMenu();
        }

        onReleased: {
            switch (position) {
            case Qt.AlignTop:
                if (menuRectangle.y < (- root.size / 2)) {
                    menuRectangle.y = -root.size;
                    root.menuIsShown = !root.menuIsShown;
                } else {
                    menuRectangle.y = 0;
                }
                break;
            case Qt.AlignBottom:
                if (menuRectangle.y < (root.height - (root.size / 2))) {
                    menuRectangle.y = root.height - root.size;
                } else {
                    menuRectangle.y = root.height;
                    root.menuIsShown = !root.menuIsShown;
                }
                break;
            case Qt.AlignLeft:
                if (menuRectangle.x < (- root.size / 2)) {
                    menuRectangle.x = - root.size;
                    root.menuIsShown = !root.menuIsShown;
                } else {
                    menuRectangle.x = 0;
                }
                break;
            case Qt.AlignRight:
                if (menuRectangle.x > root.width - (root.size / 2)) {
                    menuRectangle.x = root.width;
                    root.menuIsShown = !root.menuIsShown;
                } else {
                    menuRectangle.x = root.width - root.size;
                }
                break;
            default:
                console.log("error")
            }
        }
    }

    states: [
        State {
            name: "top"
            when: position === Qt.AlignTop

            PropertyChanges {
                target: menuRectangle

                height: root.size
                width: root.width
                y: - root.size
                x: 0

                anchors {
                    left: parent.left
                    right: parent.right
                }
            }
            PropertyChanges {
                target: dragRectangle

                anchors {
                    top: menuRectangle.bottom
                    right: parent.right
                    left: parent.left
                    bottom: parent.bottom
                }

                drag {
                    target: menuRectangle
                    axis: Drag.YAxis
                    minimumY: - root.size
                    maximumY: 0
                }
            }
        },
        State {
            name: "bottom"
            when: position === Qt.AlignBottom

            PropertyChanges {
                target: menuRectangle

                height: root.size
                width: root.width
                y: parent.height + parent.size
                x: parent.height + parent.size

                anchors {
                    left: parent.left
                    right: parent.right
                }
            }
            PropertyChanges {
                target: dragRectangle

                anchors {
                    top: parent.top
                    right: parent.right
                    left: parent.left
                    bottom: menuRectangle.top
                }

                drag {
                    target: menuRectangle
                    axis: Drag.YAxis
                    minimumY: root.height - root.size
                    maximumY: root.height
                }
            }
        },
        State {
            name: "left"
            when: position === Qt.AlignLeft

            PropertyChanges {
                target: menuRectangle

                height: root.height
                width: root.size
                y: 0
                x: - root.size

                anchors {
                    top: parent.top
                    bottom: parent.bottom
                }
            }
            PropertyChanges {
                target: dragRectangle

                anchors {
                    top: parent.top
                    right: parent.right
                    left: menuRectangle.right
                    bottom: parent.bottom
                }

                drag {
                    target: menuRectangle
                    axis: Drag.XAxis
                    minimumX: - root.size
                    maximumX: 0
                }
            }
        },
        State {
            name: "right"
            when: position === Qt.AlignRight

            PropertyChanges {
                target: menuRectangle

                height: root.height
                width: root.size
                y: root.width
                x: root.width

                anchors {
                    top: parent.top
                    bottom: parent.bottom
                }
            }
            PropertyChanges {
                target: dragRectangle

                anchors {
                    top: parent.top
                    right: menuRectangle.left
                    left: parent.left
                    bottom: parent.bottom
                }

                drag {
                    target: menuRectangle
                    axis: Drag.XAxis
                    minimumX: root.width - root.size
                    maximumX: root.width
                }
            }
        }
    ]
}
