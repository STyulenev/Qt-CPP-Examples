import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MusicPickerPage {
    id: musicPickerPage

    signal startDestroy()

    title: qsTr("Select music")

    Component.onDestruction: {
        musicPickerPage.startDestroy();
    }
}
