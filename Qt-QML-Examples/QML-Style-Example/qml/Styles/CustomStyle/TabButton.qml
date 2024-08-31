import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.TabButton {
    id: tabButton

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(
                        implicitBackgroundHeight + topInset + bottomInset,
                        implicitContentHeight + topPadding + bottomPadding,
                        implicitIndicatorHeight + topPadding + bottomPadding)

    padding: 8 * Common.Consts.xCoord
    spacing: 6 * Common.Consts.yCoord

    contentItem: Text {
        text: tabButton.text
        opacity: tabButton.enabled ? 1.0 : 0.3
        color: Common.Colors.textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight

        font {
            family: Common.Fonts.family
            bold: true
            pixelSize: Common.Fonts.pixelSize
        }
    }

    background: Rectangle {
        id: rec

        anchors.fill: parent
        radius: 2 * Common.Consts.radialSize
        anchors.margins: 5 * Common.Consts.radialSize
        opacity: tabButton.enabled ? 1 : 0.3
        color: tabButton.pressed ? tabButton.palette.highlight : Common.Colors.mainBackgroundColor

        border {
            color: Common.Colors.currentTheme.mainThemeColor
            width: (tabButton.hovered ? 2 : 1) * Common.Consts.radialSize
        }
    }
}
