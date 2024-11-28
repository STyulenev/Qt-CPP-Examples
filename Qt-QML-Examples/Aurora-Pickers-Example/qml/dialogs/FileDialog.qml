import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MultiFilePickerDialog {
    id: filePickerDialog

    signal startDestroy()

    title: qsTr("Select file")

    onAccepted: {
        filePickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
