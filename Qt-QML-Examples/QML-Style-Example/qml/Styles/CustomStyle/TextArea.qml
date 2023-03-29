import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Controls.impl 2.6
import QtQuick.Templates 2.6 as T

import Common 1.0 as Common

T.TextArea {
    id: control

    implicitWidth: Math.max(contentWidth + leftPadding + rightPadding,
                            implicitBackgroundWidth + leftInset + rightInset,
                            placeholder.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(contentHeight + topPadding + bottomPadding,
                             implicitBackgroundHeight + topInset + bottomInset,
                             placeholder.implicitHeight + topPadding + bottomPadding)

    background: Rectangle {
        color: Common.Colors.textFieldBackgroundColor
        border {
            color: Common.Colors.greyColor
            width: 1 * Common.Consts.radialSize
        }
        implicitWidth: 120 * Common.Consts.xCoord
        implicitHeight: 80 * Common.Consts.yCoord
    }

    color: Common.Colors.textFieldTextColor
    placeholderTextColor: Common.Colors.hintTextColor
    selectedTextColor: Common.Colors.textFieldTextColor

    font {
        family: Common.Fonts.family
        pixelSize: Common.Fonts.pixelSize
        bold: false
    }

    leftPadding: 16 * Common.Consts.xCoord
    rightPadding: 16 * Common.Consts.xCoord
    topPadding: 16 * Common.Consts.yCoord
    bottomPadding: 16 * Common.Consts.yCoord

    PlaceholderText {
        id: placeholder
        x: control.leftPadding
        y: control.topPadding
        width: control.width - (control.leftPadding + control.rightPadding)
        height: control.height - (control.topPadding + control.bottomPadding)

        text: control.placeholderText
        font: control.font
        color: control.placeholderTextColor
        verticalAlignment: control.verticalAlignment
        visible: !control.length && !control.preeditText && (!control.activeFocus || control.horizontalAlignment !== Qt.AlignHCenter)
        elide: Text.ElideRight
        renderType: control.renderType
    }
}
