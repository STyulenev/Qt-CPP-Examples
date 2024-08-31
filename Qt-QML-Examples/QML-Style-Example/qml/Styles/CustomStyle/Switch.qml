import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.Switch {
    id: control

    spacing: 6 * Common.Consts.xCoord

    indicator: Rectangle {
        id: indicatorRectangle
        height: 20 * Common.Consts.xCoord
        width: 100 * Common.Consts.yCoord
        x: control.leftPadding
        y: parent.height / 2 - height / 2
        enabled: control.enabled
        radius: 20 * Common.Consts.radialSize
        color: Common.Colors.mainBackgroundColor

        border {
            width: control.enabled ? (control.hovered ? 2 * Common.Consts.radialSize : 1 * Common.Consts.radialSize) : 1 * Common.Consts.radialSize
            color: Common.Colors.currentTheme.mainThemeColor
        }

        Rectangle {
            id: pill

            x: control.checked ? parent.width - width : indicatorRectangle.border.width
            y: indicatorRectangle.border.width / 2
            width: parent.height - indicatorRectangle.border.width
            height: parent.height - indicatorRectangle.border.width
            radius: 20 * Common.Consts.radialSize
            color: control.checked ?  Common.Colors.currentTheme.mainThemeColor : Common.Colors.mainBackgroundColor

            border {
                width: indicatorRectangle.border.width
                color: Common.Colors.currentTheme.mainThemeColor
            }
        }

        Text {
            text:  control.checked ? qsTr("On") : qsTr("Off")
            x: (checked ? 0: pill.width) + (parent.width - pill.width - width) / 2
            anchors.verticalCenter: parent.verticalCenter
            enabled: control.enabled
            opacity: enabled ? 1.0 : 0.3
            color: enabled ? Common.Colors.textColor : Common.Colors.hintTextColor

            font {
                family: Common.Fonts.family
                bold: true
                pixelSize: Common.Fonts.pixelSize
            }
        }
    }

    contentItem: Text {
        text: control.text

        font {
            family: Common.Fonts.family
            bold: true
            pixelSize: Common.Fonts.pixelSize
        }

        opacity: enabled ? 1.0 : 0.3
        color: control.enabled ? Common.Colors.textColor : Common.Colors.hintTextColor
        verticalAlignment: Text.AlignVCenter
        leftPadding: control.indicator.width + control.spacing
    }
}
