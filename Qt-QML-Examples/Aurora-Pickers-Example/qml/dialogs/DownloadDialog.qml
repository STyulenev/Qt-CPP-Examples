import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MultiDownloadPickerDialog {
    id: downloadPickerDialog

    signal startDestroy()

    onAccepted: {
        downloadPickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
