import QtQuick 2.6
import QtQuick.Window 2.6
import QtQuick.Templates 2.6 as Template

import Common 1.0 as Common

Template.ApplicationWindow {
    menuBar: Item {
        visible: false
    }

    color: Common.Colors.mainBackgroundColor
}
