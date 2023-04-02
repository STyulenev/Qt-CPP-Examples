import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.TabButton {
    id: tabButton
    //text: qsTr("Button")

    //implicitWidth: 100 //rec.width
    //implicitHeight: 20 //rec.height

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
        font {
            family: Common.Fonts.family
            bold: true
            pixelSize: /*tabButton.hovered ? Common.Fonts.pixelSize + 2 :*/ Common.Fonts.pixelSize
        }
        opacity: tabButton.enabled ? 1.0 : 0.3
        color: Common.Colors.textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        id: rec
        anchors.fill: parent

        anchors.margins: 5 * Common.Consts.radialSize
        opacity: tabButton.enabled ? 1 : 0.3
        //color: Common.Colors.mainBackgroundColor
        color: tabButton.pressed ? tabButton.palette.highlight : Common.Colors.mainBackgroundColor
        border {
            color: /*control.down ? "#17a81a" : "#21be2b"*/  "#4280d6"
            width: tabButton.hovered ? 2 * Common.Consts.radialSize : 1 * Common.Consts.radialSize
        }
        radius: 2 * Common.Consts.radialSize
    }
}
