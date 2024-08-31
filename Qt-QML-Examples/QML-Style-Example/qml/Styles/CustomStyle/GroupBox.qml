import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.GroupBox {
    id: groupBox

    background: Rectangle {
        y: groupBox.topPadding - groupBox.bottomPadding
        width: parent.width
        height: parent.height - groupBox.topPadding + groupBox.bottomPadding
        color: "transparent"
        radius: 7 * Common.Consts.radialSize

        border {
            width: 2 * Common.Consts.radialSize
            color: Common.Colors.mainThemeColor
        }
    }

    label: Rectangle {
        anchors {
            left: parent.left
            bottom: parent.top
            bottomMargin: - height / 2
            leftMargin: groupBox.width * 0.05
        }

        color: Common.Colors.mainBackgroundColor
        width: title.implicitWidth + 20 * Common.Consts.xCoord
        height: title.font.pixelSize

        Text {
            id: title
            text: groupBox.title
            anchors.centerIn: parent
            color: groupBox.enabled ? Common.Colors.textColor : Common.Colors.hintTextColor

            font {
                family: Common.Fonts.family
                bold: true
                pixelSize: Common.Fonts.pixelSize
            }
        }
    }
}
