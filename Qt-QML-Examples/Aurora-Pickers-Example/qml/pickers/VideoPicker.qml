import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.VideoPickerPage {
    id: videoPickerPage

    signal startDestroy()

    title: qsTr("Select video")

    Component.onDestruction: {
        videoPickerPage.startDestroy();
    }
}
