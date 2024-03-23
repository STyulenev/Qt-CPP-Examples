import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Components 1.0 as Components

/*!
   \qmltype Main.qml
   \brief Точка входа в qml

   Пример документирования файла Main.qml.

*/
Window {
    id: app

    width: 640
    height: 480
    visible: true
    title: qsTr("QDoc-Example")

    Components.ExampleComponent {
        id: exampleComponent

        anchors.centerIn: parent
        myColor: "grey"
    }
}
