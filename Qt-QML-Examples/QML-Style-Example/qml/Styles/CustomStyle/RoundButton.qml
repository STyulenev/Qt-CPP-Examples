import QtQuick 2.4
import QtQuick.Controls 2.4
import QtQuick.Templates 2.4 as T

import Common 1.0 as Common

T.RoundButton {
    id: roundButton

    font.family: Common.Fonts.family
    font.bold: true
    font.pixelSize: roundButton.hovered ? Common.Fonts.pixelSize + 2 : Common.Fonts.pixelSize
    radius: 7 * Common.Consts.radialSize
    checkable: false

    focusPolicy: Qt.NoFocus
    icon.color: roundButton.enabled ? "transparent" : Common.Colors.disabledTextColor

    // QTBUG-85685
    Component.onCompleted: {
        palette.button = (roundButton.focusPolicy === Qt.TabFocus && roundButton.enabled) ?
                    Common.Colors.activeControlColor : Common.Colors.inactiveControlColor;
        palette.highlight = (roundButton.focusPolicy === Qt.TabFocus) ?
                    Common.Colors.activePressedControlColor : Common.Colors.inactivePressedControlColor;
    }

    contentItem: IconLabel {
        id: icon
        spacing: roundButton.spacing
        mirrored: roundButton.mirrored
        display: roundButton.display
        icon: roundButton.icon
        text: roundButton.text
        font: roundButton.font
        color: roundButton.enabled ? Common.Colors.textColor : Common.Colors.disabledTextColor
    }

    background: Rectangle {
        id: background
        anchors.fill: parent
        radius: parent.radius
        color: roundButton.pressed ? roundButton.palette.highlight : roundButton.palette.button
        border.width: Common.Consts.radialSize * (roundButton.hovered ? 1 : 0)
        border.color: roundButton.hovered ? Common.Colors.textColor : Common.Colors.mainBackgroundColor
    }
}
