import QtQml 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import Components 1.0 as Components

/**
 * Главный компонент приложения
 */
ApplicationWindow {
    id: mainWindow

    width: 800
    height: 600
    visible: true
    title: qsTr("Doxyqml-Example")

    Components.SomeComponent {
        id: button

        anchors.centerIn: parent

        width: 200
        height: 100

        color: "lightblue"

        onClicked: {
            console.log("Clicked")
        }
    }
}
