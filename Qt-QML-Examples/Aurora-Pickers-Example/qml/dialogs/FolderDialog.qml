import QtQuick 2.0

import Sailfish.Pickers 1.0 as Pickers

Pickers.FolderPickerDialog {
    id: folderPickerDialog

    signal startDestroy()

    onAccepted: {
        folderPickerDialog.startDestroy();
    }

    onRejected: {
        // ...
    }
}
