import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.FilePickerPage {
    id: filePickerPage

    signal startDestroy()

    title: qsTr("Select file")

    // nameFilters: [ "*.txt", ... ]

    Component.onDestruction: {
        filePickerPage.startDestroy();
    }
}
