import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MultiMusicPickerDialog {
    id: musicPickerDialog

    signal startDestroy()

    onAccepted: {
        musicPickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
