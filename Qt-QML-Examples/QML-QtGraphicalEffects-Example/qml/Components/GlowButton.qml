import QtQuick 2.15
import QtQuick.Controls 2.15

import Qt5Compat.GraphicalEffects // - for Qt 6
//import QtGraphicalEffects 1.15  // - for Qt 5

Item {
    id: root

    signal clicked()

    property bool isGlow: false

    RoundButton {
        id: button

        anchors.fill: parent

        smooth: true
        radius: 5

        text: qsTr("GlowButton")

        onClicked: {
            root.clicked();
        }
    }

    Glow {
        id: glowEffect

        anchors.fill: button

        radius: 8
        samples: 17
        color: "blue"
        source: root.isGlow ? button : undefined
    }
}
