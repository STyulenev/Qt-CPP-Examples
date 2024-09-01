import QtQuick 2.15
import QtQuick.Controls 2.15

import Windows 1.0 as Windows

ApplicationWindow {
    id: applicationWindow

    visible: true

    width: 500
    height: 500

    title: qsTr("")

    Component {
        id: windowSomeWindow

        Windows.WindowLoader {
            window: Windows.SomeWindow {
                // ...

                onBackData: (data) => {
                    console.log(`from Windows.SomeWindow=${data}`);
                }

                onClosing: {
                    // ...
                }
            }
        }
    }

    Row {
        anchors.centerIn: parent

        Button {
            id: openWindowButton

            width: 100
            height: 50
            text: qsTr("Open window")

            onClicked: {
                windowSomeWindow.createObject(applicationWindow);
            }
        }
    }
}
