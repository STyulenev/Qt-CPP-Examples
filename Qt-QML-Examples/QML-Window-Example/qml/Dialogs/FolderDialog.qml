import QtQuick 2.15

import QtCore as Core
import QtQuick.Dialogs as Dialogs

Dialogs.FolderDialog {
    id: folderDialog

    currentFolder: Core.StandardPaths.standardLocations(Core.StandardPaths.PicturesLocation)[0]

    onSelectedFolderChanged: {
        console.log("Current folder changed: " + folderDialog.selectedFolder)
    }

    onAccepted: {
        console.log("Accept = " + folderDialog.selectedFolder)
    }

    onRejected: {
        console.log("cancel")
    }

    Component.onCompleted: {
        console.log("create FolderDialog ")
    }

    Component.onDestruction: {
        console.log("delete FolderDialog ")
    }
}
