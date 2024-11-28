import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.FolderPickerPage {
    id: folderPickerPage

    signal startDestroy()

    title: qsTr("Select folder")

    showSystemFiles: false

    Component.onDestruction: {
        folderPickerPage.startDestroy();
    }
}
