import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

import QtCore // for StandardPaths
import QtQuick.Dialogs
import QtQml 2.15

import Windows 1.0 as MyWindows
import Dialogs 1.0 as MyDialogs

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("QML-Window-Example")

    Component {
        id: componentMessageBox
        WindowLoader {
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
        DialogLoader {
            component: MyDialogs.ColorDialog {
            }
        }
    }

    Component {
        id: componentFileDialog
        DialogLoader {
            component: MyDialogs.FileDialog {
            }
        }
    }

    Component {
        id: componentFolderDialog
        DialogLoader {
            component: MyDialogs.FolderDialog {
            }
        }
    }

    Component {
        id: componentMessageDialog
        DialogLoader {
            component: MyDialogs.MessageDialog {
            }
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
                    componentMessageBox.createObject(window);
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
                componentFileDialog.createObject(window);
            }
        }

        Button {
            id: buttonMessageDialog

            height: 45
            width: 200

            text: qsTr("Open standart Message Dialog")

            onClicked: {
                componentMessageDialog.createObject(window);
            }
        }

        Button {
            id: buttonColorDialog

            height: 45
            width: 200

            text: qsTr("Open standart Color Dialog")

            onClicked: {
                componentColorDialog.createObject(window);
            }
        }

        Button {
            id: buttonFolderDialog

            height: 45
            width: 200

            text: qsTr("Open standart Folder Dialog")

            onClicked: {
                componentFolderDialog.createObject(window);
            }
        }
    }
}
