import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.GroupBox {
    id: groupBox

    background: Rectangle {
        y: groupBox.topPadding - groupBox.bottomPadding
        width: parent.width
        height: parent.height - groupBox.topPadding + groupBox.bottomPadding
        color: "transparent"
        border {
            width: 2 * Common.Consts.radialSize
            color: "#4280d6"
        }
        radius: 7 * Common.Consts.radialSize
    }

    label: Rectangle {
        anchors {
            left: parent.left
            bottom: parent.top
            bottomMargin: - height / 2
            leftMargin: groupBox.width * 0.05 //20 * Common.Consts.xCoord
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
