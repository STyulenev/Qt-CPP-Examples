import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.ContentPickerPage {
    id: contentPickerPage

    signal startDestroy()

    title: qsTr("Select content")

    Component.onDestruction: {
        contentPickerPage.startDestroy();
    }
}
