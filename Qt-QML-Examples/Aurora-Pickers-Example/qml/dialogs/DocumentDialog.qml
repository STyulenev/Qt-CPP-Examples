import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MultiDocumentPickerDialog {
    id: documentPickerDialog

    signal startDestroy()

    onAccepted: {
        documentPickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
