import QtQuick 2.15
import QtQuick.Controls 2.15

import Windows 1.0 as Windows

ApplicationWindow {
    id: applicationWindow

    visible: true

    width: 500
    height: 500

    title: qsTr("QML-Window-Example")

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

    Windows.NotificationWindow {
        id: notificationWindow

        // ...
    }

    Column {
        id: body

        anchors.centerIn: parent

        spacing: 20

        Button {
            id: openWindowButton

            width: 200
            height: 50
            text: qsTr("Open window")

            onClicked: {
                windowSomeWindow.createObject(applicationWindow);
            }
        }

        Button {
            id: notificationWindowButton

            width: 200
            height: 50
            text: qsTr("Create notification")

            onClicked: {
                notificationWindow.setNotification("Notification");
            }
        }
    }
}
