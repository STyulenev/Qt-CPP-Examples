import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.CheckBox {
    id: checkBox

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(
                        implicitBackgroundHeight + topInset + bottomInset,
                        implicitContentHeight + topPadding + bottomPadding,
                        implicitIndicatorHeight + topPadding + bottomPadding)

    padding: 6 * Common.Consts.xCoord
    spacing: 6 * Common.Consts.yCoord

    indicator: Rectangle {
        id: box

        implicitWidth: 18 * Common.Consts.xCoord
        implicitHeight: implicitWidth
        x: text ? (checkBox.mirrored ? checkBox.width - width - checkBox.rightPadding : checkBox.leftPadding) : checkBox.leftPadding
                  + (checkBox.availableWidth - width) / 2
        y: checkBox.topPadding + (checkBox.availableHeight - height) / 2

        color: checkBox.enabled ? Common.Colors.mainBackgroundColor : Common.Colors.greyColor
        border {
            width: (checkBox.hovered ? 2 : 1) * Common.Consts.radialSize
            color: checkBox.enabled ? Common.Colors.currentTheme.mainThemeColor : Common.Colors.greyColor
        }

        Image {
            id: check
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            source: (checkBox.checkState === Qt.Checked) ? "qrc:/res/check.png" : "qrc:/res/uncheck.png"
            sourceSize.height: 24 * Common.Consts.radialSize
            sourceSize.width: 24 * Common.Consts.radialSize
        }
    }

    contentItem: Text {
        id: text

        text: checkBox.text
        color: Common.Colors.textColor
        leftPadding: checkBox.indicator && !checkBox.mirrored ? checkBox.indicator.width + checkBox.spacing : 0
        rightPadding: checkBox.indicator && checkBox.mirrored ? checkBox.indicator.width + checkBox.spacing : 0

        font {
            family: Common.Fonts.family
            pixelSize:Common.Fonts.pixelSize
            bold: true
            strikeout: !checkBox.enabled
        }

        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.Wrap
    }
}
