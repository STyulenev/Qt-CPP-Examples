import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.Slider {
    id: slider

    implicitWidth: Math.max(width + leftInset + rightInset,
                            width + leftPadding + rightPadding)
    implicitHeight: Math.max(height + topInset + bottomInset,
                             height + topPadding + bottomPadding)

    background: Rectangle {
        id: back

        x: slider.leftPadding
        y: slider.topPadding + slider.availableHeight / 2 - height / 2
        width: parent.width
        height: parent.height
        radius: 2 * Common.Consts.radialSize
        color: slider.enabled ? Common.Colors.textColor : Common.Colors.greyColor

        border {
            width: 2 * Common.Consts.radialSize
            color: Common.Colors.currentTheme.mainThemeColor
        }

        Rectangle {
            width: slider.visualPosition * (parent.width - handle.width)
            height: parent.height * 0.3
            anchors {
                bottom: parent.bottom
                left: parent.left
                leftMargin: handle.width * 0.5
                rightMargin: handle.width * 0.5
            }

            color: Common.Colors.currentTheme.mainThemeColor
            radius: 2 * Common.Consts.radialSize
        }

        Canvas {
            x: slider.leftPadding + (slider.horizontal ? handle.width * 0.5 : (slider.availableWidth - width) / 2)
            y: slider.topPadding + (slider.horizontal ? (slider.availableHeight - height) / 2 : 0)
            implicitWidth: slider.horizontal ? 200 : slider.width
            implicitHeight: slider.horizontal ? slider.height : 200
            width: slider.horizontal ? slider.availableWidth - handle.width : implicitWidth
            height: slider.horizontal ? implicitHeight : slider.availableHeight - handle.height

            onPaint: {
                var ctx = getContext("2d");
                ctx.clearRect(0, 0, width, height);

                ctx.strokeStyle = Common.Colors.mainBackgroundColor;
                ctx.lineWidth = 1 * Common.Consts.yCoord;

                ctx.beginPath();
                ctx.moveTo(0, 0);
                ctx.lineTo(width, 0);
                ctx.lineTo(width, height);
                ctx.lineTo(0, height);
                ctx.lineTo(0, 0);

                var piece = width / (slider.to - slider.from);
                var count = 0;

                for (var x = 0; x < width; x += piece) {
                    ctx.moveTo(x, height);
                    if (count % 10 == 0)
                        ctx.lineTo(x, height * 0.4);
                    else
                        ctx.lineTo(x, height * 0.7);

                    count++;
                }

                ctx.stroke();
            }
        }
    }

    handle: Rectangle {
        id: handle
        x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
        y: slider.topPadding + slider.availableHeight / 2 - height / 2
        implicitWidth: 24 * Common.Consts.xCoord
        implicitHeight: slider.height
        radius: 2 * Common.Consts.radialSize
        color: "transparent"

        border {
            color: Common.Colors.currentTheme.mainThemeColor
            width: 2 * Common.Consts.radialSize
        }

        Text {
            id: text
            z: 2
            text: qsTr("%1").arg(slider.value)
            color: Common.Colors.mainBackgroundColor
            anchors.centerIn: parent

            font {
                family: Common.Fonts.family
                pixelSize:Common.Fonts.pixelSize
                bold: true
            }

            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.Wrap
        }
    }
}
