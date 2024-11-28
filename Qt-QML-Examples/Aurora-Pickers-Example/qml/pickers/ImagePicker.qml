import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.ImagePickerPage {
    id: imagePickerPage

    signal startDestroy()

    title: qsTr("Select image")

    Component.onDestruction: {
        imagePickerPage.startDestroy();
    }
}
