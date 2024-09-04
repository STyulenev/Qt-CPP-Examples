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

    /*Components.FastBlurButton {
        id: blurButton

        anchors.centerIn: parent

        width: 150
        height: 80

        isBlur: true

        onClicked: {
            console.log("FastBlur button clicked");
        }
    }*/

    /*Components.GlowButton {
        id: glowButton

        anchors.centerIn: parent

        width: 150
        height: 80

        isGlow: true

        onClicked: {
            console.log("Glow button clicked");
        }
    }*/

    /*Components.ColorOverlayImage {
        id: colorOverlayImage

        anchors.centerIn: parent

        width: 100
        height: 100

        source: "qrc:/res/warning-icon.svg"

        overlayColor: "blue"
    }*/

    Components.DirectionalBlurButton {
        id: directionalBlurButton

        anchors.centerIn: parent

        width: 160
        height: 80

        isBlur: true

        onClicked: {
            console.log("DirectionalBlur button clicked");
        }
    }
}
