import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Templates 2.6 as T

import Common 1.0 as Common

T.Label {
    color: enabled ? Common.Colors.textColor : Common.Colors.hintTextColor
    font.family: Common.Fonts.family
    font.bold: true
    font.pixelSize: Common.Fonts.pixelSize
}
