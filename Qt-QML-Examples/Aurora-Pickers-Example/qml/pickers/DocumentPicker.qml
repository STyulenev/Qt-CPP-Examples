import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.DocumentPickerPage {
    id: documentPickerPage

    signal startDestroy()

    title: qsTr("Select document")

    Component.onDestruction: {
        documentPickerPage.startDestroy();
    }
}
