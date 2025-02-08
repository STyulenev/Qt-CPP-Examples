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
        id: simpleWindowComponent

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

    Component {
        id: customWindowComponent

        Windows.CustomWindow {
            // ...

            onClosing: {
                // ...
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
            id: openSimpleWindowButton

            width: 200
            height: 50
            text: qsTr("Open simple window")

            onClicked: {
                simpleWindowComponent.createObject(applicationWindow);
            }
        }

        Button {
            id: openCustomWindowButton

            width: 200
            height: 50
            text: qsTr("Open custom window")

            onClicked: {
                customWindowComponent.createObject(applicationWindow);
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
