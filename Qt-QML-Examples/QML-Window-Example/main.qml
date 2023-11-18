import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

import QtCore // for StandardPaths
import QtQuick.Dialogs
import QtQml 2.15

import Windows 1.0 as MyWindows

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Window-Example")

    Component {
        id: component
        ComponentLoader {
            component: MyWindows.MessageBox {
                title: "Are you sure?"
                btnType: mb_YES | mb_NO | mb_CANCEL;

                Component.onDestruction: {
                    if (retValue === mb_YES) {
                        console.log("yes");
                    } else if(retValue === mb_NO) {
                        console.log("no");
                    } else if(retValue === mb_CANCEL) {
                        console.log("cancel");
                    }
                }
            }
        }
    }

    FileDialog {
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

    MessageDialog {
        id: messageDialog

        title: qsTr("Title")
        text: qsTr("Text")
        //detailedText: qsTr("detailed")

        buttons: MessageDialog.Yes | MessageDialog.No | MessageDialog.Abort
        Component.onCompleted: visible = false

        onAccepted: {
            console.log("Accept")
        }

        onRejected: {
            console.log("cancel")
        }
    }

    ColorDialog {
        id: colorDialog
        visible: false
        modality: /*colorDialogModal.checked ?*/ Qt.WindowModal //: Qt.NonModal
        title: "Choose a color"
        //color: "green"
        //showAlphaChannel: true //colorDialogAlpha.checked
        onAccepted: (color) =>  {
            console.log("Accepted: " + color)
        }

        onRejected: {
            console.log("Rejected")
        }

        Component.onCompleted: {
            console.log("create ColorDialog ")
        }

        Component.onDestruction: {
            console.log("delete ColorDialog ")
        }
    }

    FolderDialog {
        id: folderDialog
        currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]

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

    Column {
        anchors.centerIn: parent

        Button {
            id: buttonCustomMessageBox

            height: 45
            width: 200

            text: qsTr("Open custom MessageBox")

            onClicked: {
                var openWithLoader = true;

                if (openWithLoader) {
                    // Component + Loader
                    component.createObject(window);
                } else {
                    // Qt.createComponent
                    var dlg = Qt.createComponent("qrc:/qml/Windows/MessageBox.qml", Component.Asynchronous).createObject(window);

                    dlg.btnType = dlg.mb_YES | dlg.mb_NO | dlg.mb_CANCEL;
                    dlg.title = "Are you sure?"
                    dlg.closing.connect(function (){
                        if (dlg.retValue === dlg.mb_YES) {
                            console.log("yes");
                        } else if(dlg.retValue === dlg.mb_NO) {
                            console.log("no");
                        } else if(dlg.retValue === dlg.mb_CANCEL) {
                            console.log("cancel");
                        }

                        dlg.destroy();
                    });
                    dlg.show();
                }
            }
        }

        Button {
            id: buttonFileDialog

            height: 45
            width: 200

            text: qsTr("Open standart File Dialog")

            onClicked: {
                fileDialog.open();
            }
        }

        Button {
            id: buttonMessageDialog

            height: 45
            width: 200

            text: qsTr("Open standart Message Dialog")

            onClicked: {
                messageDialog.open();
            }
        }

        Button {
            id: buttonColorDialog

            height: 45
            width: 200

            text: qsTr("Open standart Color Dialog")

            onClicked: {
                colorDialog.open();
            }
        }

        Button {
            id: buttonFolderDialog

            height: 45
            width: 200

            text: qsTr("Open standart Folder Dialog")

            onClicked: {
                folderDialog.open();
            }
        }
    }
}
