import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.PrinterPickerPage {
    id: printerPickerPage

    signal startDestroy()

    Component.onDestruction: {
        printerPickerPage.startDestroy();
    }
}
