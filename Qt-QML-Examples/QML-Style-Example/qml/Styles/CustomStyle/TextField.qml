import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.TextField {
    id: textField

    implicitWidth: implicitBackgroundWidth + leftInset + rightInset || Math.max(
                       contentWidth,
                       placeholderText.implicitWidth) + leftPadding + rightPadding
    implicitHeight: Math.max(
                        implicitBackgroundHeight + topInset + bottomInset,
                        contentHeight + topPadding + bottomPadding,
                        placeholderText.implicitHeight + topPadding + bottomPadding)

    color: Common.Colors.textFieldTextColor
    placeholderTextColor: Common.Colors.hintTextColor
    selectedTextColor: Common.Colors.textFieldTextColor

    font {
        family: Common.Fonts.family
        pixelSize: Common.Fonts.pixelSize
        bold: false
    }

    selectionColor: Common.Colors.textFieldSelectionColor
    selectByMouse: true

    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignLeft

    leftPadding: 6 * Common.Consts.xCoord
    rightPadding: 6 * Common.Consts.xCoord
    topPadding: 0
    bottomPadding: 0

    background: Rectangle {
        color: textField.enabled ? Common.Colors.textFieldBackgroundColor : Common.Colors.textFieldDisabledBackgroundColor
        border.width: 2 * Common.Consts.radialSize
        border.color: textField.enabled ? (textField.activeFocus ?
                                               Common.Colors.mainThemeColor : Common.Colors.textFieldBackgroundColor)
                                        : Common.Colors.textFieldDisabledBackgroundColor
        implicitWidth: 120 * Common.Consts.xCoord
        implicitHeight: 29 * Common.Consts.yCoord
    }

    cursorDelegate: Rectangle {
        id: cursor
        visible: textField.cursorVisible
        color: Common.Colors.textFieldTealCursorColor
        width: textField.cursorRectangle.width * Common.Consts.yCoord
        SequentialAnimation {
            PropertyAction {
                target: cursor
                property: "opacity"
                value: 1
            }
            NumberAnimation {
                duration: 500
            }
            PropertyAction {
                target: cursor
                property: "opacity"
                value: 0
            }
            NumberAnimation {
                duration: 500
            }
            running: textField.cursorVisible
            loops: Animation.Infinite
        }
    }

    PlaceholderText {
        id: placeholderText
        x: textField.leftPadding
        y: textField.topPadding
        width: textField.width - (textField.leftPadding + textField.rightPadding)
        height: textField.height - (textField.topPadding + textField.bottomPadding)
        text: textField.placeholderText
        font: textField.font
        color: textField.placeholderTextColor
        verticalAlignment: textField.verticalAlignment
        elide: Text.ElideRight
        renderType: textField.renderType
        visible: !textField.length && !textField.preeditText
                 && (!textField.activeFocus
                     || textField.horizontalAlignment !== Qt.AlignHCenter)
    }
}
