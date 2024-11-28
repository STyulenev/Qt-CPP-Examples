import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MultiVideoPickerDialog {
    id: videoPickerDialog

    signal startDestroy()

    onAccepted: {
        videoPickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
