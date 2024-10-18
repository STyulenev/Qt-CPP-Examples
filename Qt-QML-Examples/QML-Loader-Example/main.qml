import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Loader-Example")

    QtObject {
        id: internal

        property color itemColor: "white"

        onItemColorChanged: {
            console.log(itemColor)
        }
    }

    Loader {
        id: myLoader

        anchors.centerIn: parent

        width: 200
        height: 200

        sourceComponent: {
            var type = 0; // 0, 1, ...

            switch(type) {
            case 0: return newComponent1;
            case 1: return newComponent2;
            default:
                return newComponent1;
            }
        }

        onLoaded: {
            internal.itemColor = Qt.binding(function() { return myLoader.item.color });

            myLoader.item.message.connect(function (msg) { console.log(msg) });
        }
    }

    /*Connections {
        target: myLoader.item
        function onMessage(msg) { console.log(msg) }
    }

    Binding {
        internal.itemColor: myLoader.item.color
    }*/

    Component {
        id: newComponent1

        Rectangle {
            id: myItem

            signal message(string msg)



            anchors.fill: parent

            color: "blue"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myItem.message("clicked 1!")
                    myItem.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
                }
            }
        }
    }

    Component {
        id: newComponent2

        Rectangle {
            id: myItem

            signal message(string msg)

            anchors.fill: parent

            color: "red"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myItem.message("clicked 2!")
                    myItem.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
                }
            }
        }
    }
}
