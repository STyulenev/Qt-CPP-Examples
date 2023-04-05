import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.TextArea {
    id: textArea

    implicitWidth: Math.max(contentWidth + leftPadding + rightPadding,
                            implicitBackgroundWidth + leftInset + rightInset,
                            placeholderText.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(contentHeight + topPadding + bottomPadding,
                             implicitBackgroundHeight + topInset + bottomInset,
                             placeholderText.implicitHeight + topPadding + bottomPadding)

    background: Rectangle {
        color: Common.Colors.textFieldBackgroundColor
        implicitWidth: 120 * Common.Consts.xCoord
        implicitHeight: 80 * Common.Consts.yCoord

        border {
            width: 2 * Common.Consts.radialSize
            color: textArea.enabled ? (textArea.activeFocus ?
                                           Common.Colors.mainThemeColor : Common.Colors.textFieldBackgroundColor)
                                    : Common.Colors.textFieldDisabledBackgroundColor
        }
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
        id: placeholderText
        x: textArea.leftPadding
        y: textArea.topPadding
        width: textArea.width - (textArea.leftPadding + textArea.rightPadding)
        height: textArea.height - (textArea.topPadding + textArea.bottomPadding)

        text: textArea.placeholderText
        font: textArea.font
        color: textArea.placeholderTextColor
        verticalAlignment: textArea.verticalAlignment
        visible: !textArea.length && !textArea.preeditText && (!textArea.activeFocus || textArea.horizontalAlignment !== Qt.AlignHCenter)
        elide: Text.ElideRight
        renderType: textArea.renderType
    }
}
