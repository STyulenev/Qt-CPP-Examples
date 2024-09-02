import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Components 1.0 as Components

ApplicationWindow {
    id: app

    visible: true
    width: 640
    height: 480
    title: qsTr("QML-QtGraphicalEffects-Example")

    Components.BlurButton {
        id: blurButton

        anchors.centerIn: parent

        width: 150
        height: 80

        isBlur: true

        onClicked: {
            console.log("Blur button clicked");
        }
    }
}
