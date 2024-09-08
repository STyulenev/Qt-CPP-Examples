import QtQuick 2.15
import QtQuick.Controls 2.15

import Qt5Compat.GraphicalEffects // - for Qt 6
//import QtGraphicalEffects 1.15  // - for Qt 5

Item {
    id: root

    signal clicked()

    property bool isBlur: false

    Button {
        id: button

        anchors.fill: parent

        smooth: true
        enabled: !root.isBlur

        icon.source: "qrc:/res/warning-icon.svg"

        text: qsTr("BlurButton")

        onClicked: {
            root.clicked();
        }
    }

    FastBlur {
        id: blurEffect

        anchors.fill: button
        source: root.isBlur ? button : undefined
        radius: 32
    }
}
