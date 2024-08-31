import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as Template

import Common 1.0 as Common

Template.Label {
    color: enabled ? Common.Colors.textColor : Common.Colors.hintTextColor
    font {
        family: Common.Fonts.family
        bold: true
        pixelSize: Common.Fonts.pixelSize
    }
}
