import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import ViewModels 1.0 as MyViewModels

Window {
    id: mainWindow

    width: 640
    height: 480
    visible: true

    title: qsTr("Hello World")

    property QtObject currentModel: MyViewModels.TranslateViewModel {}

    Column {
        anchors.centerIn: parent
        spacing: 10

        Label {
            height: 30
            width: 200
            text: qsTr("Hello World")
        }

        Button {
            height: 30
            width: 200
            text: qsTr("to rus")

            onClicked: {
                currentModel.setRu();
            }
        }

        Button {
            height: 30
            width: 200
            text: qsTr("to en")

            onClicked: {
                currentModel.setEn();
            }
        }
    }
}
