import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.MultiImagePickerDialog {
    id: imagePickerDialog

    signal startDestroy()

    onAccepted: {
        imagePickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
