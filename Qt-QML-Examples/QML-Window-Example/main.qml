import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

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

                onClosing: {
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

    Button {
        id: button
        anchors.centerIn: parent
        text: "show"

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
}
