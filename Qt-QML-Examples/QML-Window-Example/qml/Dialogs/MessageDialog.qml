import QtQuick 2.15

import QtQuick.Dialogs as Dialogs

Dialogs.MessageDialog {
    id: messageDialog

    title: qsTr("Title")
    text: qsTr("Text")
    //detailedText: qsTr("detailed")

    buttons: Dialogs.MessageDialog.Yes | Dialogs.MessageDialog.No | Dialogs.MessageDialog.Abort

    onAccepted: {
        console.log("Accept")
    }

    onRejected: {
        console.log("cancel")
    }
}
