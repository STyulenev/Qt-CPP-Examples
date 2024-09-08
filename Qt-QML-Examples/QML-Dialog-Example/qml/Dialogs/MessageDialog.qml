import QtQuick 2.15

import QtQuick.Dialogs as StandartDialogs

StandartDialogs.MessageDialog {
    id: messageDialog

    title: qsTr("Title")
    text: qsTr("Text")
    //detailedText: qsTr("detailed")

    buttons: StandartDialogs.MessageDialog.Yes | StandartDialogs.MessageDialog.No | StandartDialogs.MessageDialog.Abort

    onAccepted: {
        console.log("Accept")
    }

    onRejected: {
        console.log("cancel")
    }
}
