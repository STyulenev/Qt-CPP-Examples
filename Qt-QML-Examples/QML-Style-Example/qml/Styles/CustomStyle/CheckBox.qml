import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Controls.impl 2.6
import QtQuick.Templates 2.6 as Template

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

            width: /*checkBox.enabled ? 2 : 0 ||*/ checkBox.hovered ? 4 : 2
            color: checkBox.enabled ? "#4280d6" : Common.Colors.greyColor //checkBox.checked ? Common.Colors.activeControlColor : checkBox.palette.light
        }

        Image {
            id: check
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            source: (checkBox.checkState === Qt.Checked) ? "qrc:/res/check.png" : "qrc:/res/uncheck.png"
            sourceSize.height: 24 * Common.Consts.radialSize
            sourceSize.width: 24 * Common.Consts.radialSize
            //visible: checkBox.checkState === Qt.Checked
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

        }
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.Wrap
    }
}
