import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Qt.labs.platform 1.1

ApplicationWindow {
    id: application

    visible: true
    width: 640
    height: 480
    title: qsTr("QML-SystemTrayIcon")

    QtObject {
        id: internal

        property bool isTray: true
    }

    SystemTrayIcon {
        id: systemTray

        visible: true

        icon.source: "qrc:/res/icons-tray.png"
        tooltip: "Tray Program Работа со сворачиванием программы трей"

        onActivated: (reason) => {
            if (reason === 1){
                trayMenu.open()
            } else {
                if(application.visibility === Window.Hidden) {
                    application.show()
                } else {
                    application.hide()
                }
            }
        }
    }

    Menu {
        id: trayMenu

        MenuItem {
            text: qsTr("Развернуть окно")
            onTriggered: application.show()
        }

        MenuItem {
            text: qsTr("Выход")
            onTriggered: {
                internal.isTray = false;
                systemTray.hide()
                Qt.quit()
            }
        }
    }

    onClosing: (close) => {
        if (internal.isTray){
            close.accepted = false
            application.hide()

            systemTray.showMessage("QML-SystemTrayIcon", qsTr("Приложение свёрнуто."))
        } else {
            Qt.quit()
        }
    }
}
