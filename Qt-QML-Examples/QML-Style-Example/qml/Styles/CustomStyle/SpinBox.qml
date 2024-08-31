import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.SpinBox {
    id: spinBox

    contentItem: TextField {
        z: 1
        text: spinBox.textFromValue(spinBox.value, spinBox.locale)
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        readOnly: true
        validator: spinBox.validator
        inputMethodHints: Qt.ImhFormattedNumbersOnly
    }

    up.indicator: RoundButton {
        text: "+"
        x: spinBox.mirrored ? 0 : parent.width - width
        z: 2
        height: parent.height
        width: parent.width / 4
        radius: 0

        onClicked: spinBox.increase();
    }

    down.indicator: RoundButton {
        text: "-"
        x: spinBox.mirrored ? parent.width - width : 0
        z: 2
        height: parent.height
        width: parent.width / 4
        radius: 0

        onClicked: spinBox.decrease();
    }
}
