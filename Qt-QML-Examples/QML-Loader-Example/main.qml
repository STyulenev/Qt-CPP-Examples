import QtQuick
import QtQuick.Window

import Components 1.0 as Components

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Loader-Example")

    // Пример для Binding
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
            // Connections и Binding через Qt методы
            internal.itemColor = Qt.binding(function() { return myLoader.item.color });
            myLoader.item.message.connect(function (msg) { console.log(msg) });
        }
    }

    // Connections и Binding как отдельные компоненты
    /*Connections {
        target: myLoader.item
        function onMessage(msg) { console.log(msg) }
    }

    Binding {
        internal.itemColor: myLoader.item.color
    }*/

    Component {
        id: newComponent1

        Components.Component1 { }
    }

    Component {
        id: newComponent2

        Components.Component2 { }
    }

    /*Component {
        id: newComponent3

        Rectangle {
            ...
        }
    }*/
}
