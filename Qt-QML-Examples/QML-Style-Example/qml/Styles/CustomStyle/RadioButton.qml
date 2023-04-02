import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Controls.impl 2.6
import QtQuick.Templates 2.6 as Template

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
        border.width: radioButton.hovered ? 4 : 2
        border.color: "#4280d6" //radioButton.checked ? Common.Colors.activeControlColor : radioButton.palette.light

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
                context.fillStyle = "#4280d6";
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
        }
        color: Common.Colors.textColor
        font.pixelSize: Common.Fonts.pixelSize
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
    }
}
