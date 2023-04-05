import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.RoundButton {
    id: roundButton

    width: roundButton.hovered ? roundButton.width * 1.1 : roundButton.width
    height:  roundButton.hovered ? roundButton.height * 1.05 : roundButton.height
    radius: 7 * Common.Consts.radialSize
    checkable: false
    focusPolicy: Qt.NoFocus
    icon.color: roundButton.enabled ? "transparent" : Common.Colors.disabledTextColor

    font {
        family: Common.Fonts.family
        bold: true
        pixelSize: roundButton.hovered ? Common.Fonts.pixelSize + 2 : Common.Fonts.pixelSize
    }

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
        border {
            width: (roundButton.hovered ? 1 : 0) * Common.Consts.radialSize
            color: roundButton.hovered ? Common.Colors.mainThemeColor : Common.Colors.mainBackgroundColor
        }
    }
}
