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

    function onMenu() { // изменение местоположения
        switch (position) {
        case Qt.AlignTop:
            menuRectangle.y = root.menuIsShown ? -root.size : 0;
            break;
        case Qt.AlignBottom:
            menuRectangle.y = root.menuIsShown ? root.height + root.size : - root.size + root.height;
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

        Text {
            id: labelName

            text: "Menu"
            anchors.fill: parent
            Layout.alignment: Qt.AlignCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 14
            font.family: "Helvetica"
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
                menuProgressOpening = Math.abs(1 -(menuRectangle.y - (root.stateY - 2 * root.size)) / (root.stateY  - (root.stateY - 2  * root.size))) * 0.5;
                console.log("Progress = " + (menuProgressOpening))
                break;
            default:
                // ...
                break;
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
                // ...
                break;
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
        }
    ]
}
