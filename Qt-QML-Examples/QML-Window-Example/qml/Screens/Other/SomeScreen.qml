import QtQml 2.15
import QtQuick 2.15

import Windows 1.0 as MyWindows
import Dialogs 1.0 as MyDialogs
import Screens 1.0 as Screens

SomeScreen_Form {
    id: formSomeScreen

    Component {
        id: componentMessageBox
        Screens.WindowLoader {
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

    Component {
        id: componentColorDialog
        Screens.DialogLoader {
            component: MyDialogs.ColorDialog {
            }
        }
    }

    Component {
        id: componentFileDialog
        Screens.DialogLoader {
            component: MyDialogs.FileDialog {
            }
        }
    }

    Component {
        id: componentFolderDialog
        Screens.DialogLoader {
            component: MyDialogs.FolderDialog {
            }
        }
    }

    Component {
        id: componentMessageDialog
        Screens.DialogLoader {
            component: MyDialogs.MessageDialog {
            }
        }
    }

    onButtonCustomMessageBoxClicked: {
        var openWithLoader = true;

        if (openWithLoader) {
            // Component + Loader
            componentMessageBox.createObject(formSomeScreen);
        } else {
            // Qt.createComponent
            var dlg = Qt.createComponent("qrc:/qml/Windows/MessageBox.qml", Component.Asynchronous).createObject(formSomeScreen);

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

    onButtonFileDialogClicked: {
        componentFileDialog.createObject(formSomeScreen);
    }

    onButtonMessageDialogClicked: {
        componentMessageDialog.createObject(formSomeScreen);
    }

    onButtonColorDialogClicked: {
        componentColorDialog.createObject(formSomeScreen);
    }

    onButtonFolderDialogClicked: {
        componentFolderDialog.createObject(formSomeScreen);
    }
}
