import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.RadioButton {
    id: radioButton

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

        implicitWidth: 20 * Common.Consts.xCoord
        implicitHeight: implicitWidth
        radius: width / 2
        x: text ? (radioButton.mirrored ? radioButton.width - width - radioButton.rightPadding : radioButton.leftPadding) : radioButton.leftPadding
                  + (radioButton.availableWidth - width) / 2
        y: radioButton.topPadding + (radioButton.availableHeight - height) / 2
        color: radioButton.enabled ? Common.Colors.mainBackgroundColor : Common.Colors.greyColor
        border {
            width: (radioButton.hovered ? 2 : 1) * Common.Consts.radialSize
            color: Common.Colors.currentTheme.mainThemeColor
        }

        Canvas {
            id: dot

            width: box.height
            height: box.height

            visible: radioButton.checkState === Qt.Checked
                     || (radioButton.checked
                         && radioButton.checkState === undefined)
                     || (radioButton.checked && !radioButton.enabled)

            onPaint: {
                var context = getContext("2d");
                context.reset();
                context.arc(height / 2, height / 2, height / 3, 0 * Math.PI, 2 * Math.PI);
                context.fillStyle = Common.Colors.currentTheme.mainThemeColor;
                context.fill();
            }
        }
    }

    contentItem: Text {
        id: text

        text: radioButton.text
        leftPadding: radioButton.indicator && !radioButton.mirrored ? radioButton.indicator.width + radioButton.spacing : 0
        rightPadding: radioButton.indicator && radioButton.mirrored ? radioButton.indicator.width + radioButton.spacing : 0

        font {
            bold: true
            family: Common.Fonts.family
            underline: radioButton.hovered
            strikeout: !radioButton.enabled
        }
        color: Common.Colors.textColor
        font.pixelSize: Common.Fonts.pixelSize
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
    }
}
