import QtQuick 2.15

import QtQuick.Dialogs as Dialogs

Dialogs.FileDialog {
    id: fileDialog

    title: qsTr("Open txt file")
    nameFilters: ["Text files (*.txt)"]

    acceptLabel: qsTr("OK")
    rejectLabel: qsTr("Cancel")

    fileMode: FileDialog.OpenFile

    onAccepted: {
        console.log("You chose: " + fileDialog.currentFiles)
    }

    onRejected: {
        console.log("cancel")
    }

    Component.onCompleted: {
        console.log("create FileDialog ")
    }

    Component.onDestruction: {
        console.log("delete FileDialog ")
    }
}
