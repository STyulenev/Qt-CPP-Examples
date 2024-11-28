import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.DownloadPickerPage {
    id: downloadPickerPage

    signal startDestroy()

    title: qsTr("Select download file")

    Component.onDestruction: {
        downloadPickerPage.startDestroy();
    }
}
