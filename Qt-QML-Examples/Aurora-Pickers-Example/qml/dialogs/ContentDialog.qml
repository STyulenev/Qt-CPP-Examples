import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MultiContentPickerDialog {
    id: contentPickerDialog

    signal startDestroy()

    title: qsTr("Select content")

    onAccepted: {
        contentPickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
